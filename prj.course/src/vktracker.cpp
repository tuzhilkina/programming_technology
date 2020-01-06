#include "vktracker.h"

vktracker::vktracker(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::vktracker)
{
	ui->setupUi(this);
	vk = new VK;

	QCoreApplication::setApplicationName("vktracker");

	connect(ui->login, SIGNAL(clicked()), this, SLOT(slotLogin()));
	connect(ui->logout, SIGNAL(clicked()), this, SLOT(slotLogout()));
	connect(ui->addLink, SIGNAL(returnPressed()), this, SLOT(addLink()));
	connect(vk, &VK::resultReady, this, &vktracker::showNotification);
	connect(ui->following, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(stopFollowing(QListWidgetItem*)));
	connect(ui->notification, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(closeNotification(QListWidgetItem*)));
	connect(ui->load, SIGNAL(clicked()), this, SLOT(loadID()));
	connect(ui->cleanAll, SIGNAL(clicked()), this, SLOT(stopAll()));

	ui->addLink->setVisible(false);
	QPixmap vktrack("/vktracker/vktracker2.jpg");
	QPixmap clean("/vktracker/delete_all.png");
	ui->logo->setPixmap(vktrack);
	ui->cleanAll->setIcon(clean);
	QIcon icon("/vktracker/icon.png");
	tray_icon = new QSystemTrayIcon(icon);
	tray_icon->show();
	QWidget::setWindowIcon(icon);
	QString toLoad = loadSettings();

	if (vk->access_token != "" && vk->user_id != "") {
		ui->userPhoto->setVisible(true);
		ui->login->setVisible(false);
		ui->logout->setVisible(true);
		vk->getUserInfo(vk->user_id, ui->userName, ui->userPhoto);
		ui->addLink->show();
	}
	else {
		ui->login->setVisible(true);
		ui->logout->setVisible(false);
		ui->userPhoto->setVisible(false);
	}

	ui->addLink->setToolTip(QString::fromLocal8Bit("Введите только id."));
	ui->following->setToolTip(QString::fromLocal8Bit("Двойной клик ЛКМ, чтобы прекратить отслеживание."));
	ui->notification->setToolTip(QString::fromLocal8Bit("Двойной клик ЛКМ, чтобы скрыть уведомление."));
}

vktracker::~vktracker() {
	vk->cancelation = true;
	saveSettings();
	ui->following->clear(); //delete all *item
	ui->notification->clear();
	for (ptrdiff_t i(0); i < online.size(); i += 1) {
		delete online.at(i)->ui;
		delete online.at(i);

	}
	for (ptrdiff_t i(0); i < list.size(); i += 1) {
		delete list.at(i)->ui;
		delete list.at(i);
	}
	delete tray_icon;
	tray_icon = nullptr;
	delete vk;
	vk = nullptr;
}

void vktracker::closeEvent(QCloseEvent* event) {
	vk->cancelation = true;
}

void vktracker::saveSettings() {
	QString ids("");
	if (list.size() != 0) {
		for (ptrdiff_t i(0); i < list.size(); i += 1) {
			ids += list.at(i)->id + "*";
		}
	}

	QSettings sett("/vktracker/config.ini", QSettings::IniFormat);
	sett.setValue("SECTION/AC", vk->access_token);
	sett.setValue("SECTION/US", vk->user_id);
	sett.setValue("SECTION/ID", ids);
}

QString vktracker::loadSettings() {
	QString ids("");
	QSettings sett("/vktracker/config.ini", QSettings::IniFormat);
	if (sett.contains("SECTION/AC")) {
		vk->access_token = sett.value("SECTION/AC", "").toString();
	}
	if (sett.contains("SECTION/ID")) {
		ids = sett.value("SECTION/ID", "").toString();
	}
	if (sett.contains("SECTION/US")) {
		vk->user_id = sett.value("SECTION/US", "").toString();
	}
	return ids;
}

void vktracker::slotLogin() {
	ui->userPhoto->setVisible(true);
	Login login;
	login.setModal(true);
	login.exec();
	vk->access_token = login.access_token;
	vk->user_id = login.user_id;
	vk->getUserInfo(vk->user_id, ui->userName, ui->userPhoto);
	ui->addLink->show();
	if (vk->access_token != "") {
		ui->login->setVisible(false);
		ui->logout->setVisible(true);
	}
	else {
		ui->login->setVisible(true);
		ui->logout->setVisible(false);
	}
}

void vktracker::slotLogout() {
	vk->access_token = "";
	vk->user_id = "";
	ui->userName->setText(QString::fromLocal8Bit("Вход не выполнен"));
	ui->userPhoto->setVisible(false);

	vk->cancelation = true;

	list.clear();
	ui->following->clear();
	ui->notification->clear();
	if (vk->access_token != "") {
		ui->login->setVisible(false);
		ui->logout->setVisible(true);
	}
	else {
		ui->login->setVisible(true);
		ui->logout->setVisible(false);
	}
};

void vktracker::addLink() {
	QString id_ = ui->addLink->text();
	Followed* person = new Followed;
	person->id = id_;
	person->ui->link->setText(id_);
	person->item->setSizeHint(person->sizeHint());
	vk->getUserInfo(person->id, person->ui->name, person->ui->photo);

	if (person->ui->name->text() != "") {
		vk->cancelation = true;
		ui->addLink->setText("");
		bool repeat(false);
		for (ptrdiff_t i(0); i < list.size(); i += 1) {
			if (list.at(i)->id == id_) repeat = true;
		}

		if (!repeat) {
			list.append(person);
			ui->following->addItem(list.back()->item);
			ui->following->setItemWidget(list.back()->item, list.back());
		}
		if (list.size() != 0) {
			vk->cancelation = false;
			vk->track(list);
		}
	}
	else {
		ui->addLink->setText(QString::fromLocal8Bit("Введите верный id"));
	}
}

void vktracker::showNotification(QList<Followed*> online_) {
	QSound::play("/vktracker/zvuk.wav");
	online = online_;

	for (ptrdiff_t l(0); l < list.size(); l += 1) {
		for (ptrdiff_t o(0); o < online.size(); o += 1) {
			if (list.at(l)->id == online.at(o)->id) {
				delete ui->following->item(ui->following->row(list.at(l)->item));
				list.removeAt(l);
				ui->notification->addItem(online.at(o)->item);
				ui->notification->setItemWidget(online.at(o)->item, online.at(o));
			}
		}
	}
}

void vktracker::stopFollowing(QListWidgetItem* item) {
	vk->cancelation = true;
	for (ptrdiff_t i(0); i < list.size(); i += 1) {
		if (item == list.at(i)->item) {
			delete ui->following->item(ui->following->row(item));
			list.at(i)->item = nullptr;
			delete list.at(i)->ui;
			list.removeAt(i);
		}
	}
	if (list.size() != 0) {
		vk->cancelation = false;
		vk->track(list);
	}
}

void vktracker::closeNotification(QListWidgetItem* item) {
	for (ptrdiff_t i(0); i < online.size(); i += 1) {
		if (item == online.at(i)->item) {
			delete ui->notification->item(ui->notification->row(item));
			online.at(i)->item = nullptr;
			delete online.at(i)->ui;
			online.removeAt(i);
		}
	}
}

void vktracker::loadID() {
	vk->cancelation = true;
	QString temp = loadSettings();
	QStringList id = temp.split('*');
	if (temp != "") {
		for (ptrdiff_t i(0); i < id.size(); i += 1) {
			if (id.at(i) != "") {
				Followed* person = new Followed;
				person->id = id.at(i);
				person->ui->link->setText(id.at(i));
				person->item->setSizeHint(person->sizeHint());
				vk->getUserInfo(person->id, person->ui->name, person->ui->photo);
				list.append(person);
				ui->following->addItem(list.back()->item);
				ui->following->setItemWidget(list.back()->item, list.back());
			}
		}
		if (list.size() != 0) {
			vk->cancelation = false;
			vk->track(list);
		}
	}
}

void vktracker::stopAll() {
	vk->cancelation = true;
	ui->following->clear(); //delete all item
	for (ptrdiff_t i(0); i < list.size(); i += 1) {
		list.at(i)->item = nullptr;
		delete list.at(i)->ui;
	}
	list.clear(); //delete Followed
}