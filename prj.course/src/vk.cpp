#include "vk.h"

VK::VK(QObject* parent)
	: QObject(parent)
{
}

VK::~VK() {
	delete timer;
	delete manager;
}

//��������� ������� JSON �� ������ �������
QJsonObject VK::ObjectFromString(const QString& in) {
	//JSON-������, ���������� � ���������� ��������
	QJsonObject obj;
	//JSON-�������� �� ������ ������ �������
	QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());

	//���� ������� ��������� ������ �������
	if (!doc.isNull()) {
		if (doc.isObject()) { obj = doc.object(); }
		else { qDebug() << "Document is not an object" << endl; }
	}
	else { qDebug() << "Invalid JSON..." << in << endl; }
	return obj;
}

//�������� url � ������� ������� �� ������ ��
QJsonObject VK::sendRequest(const QString& in) {
	QUrl url(in);
	QNetworkRequest request(url);
	QNetworkReply* reply = manager->get(request);

	//�������, ������������ � ��������� ������ � �������
	QEventLoop loop;
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();

	//�������� �����
	QByteArray content = reply->readAll();
	//������������� � ������
	QString str = QString::fromUtf8(content.data(), content.size());
	//�������� QJsonObject �� ������ ������
	QJsonObject jobj = ObjectFromString(str);
	return jobj;
}

//�������� � ���������� ��������� ������������
QByteArray VK::getPhoto(const QString& photo_50) {
	QUrl url(photo_50);
	QNetworkRequest request(url);
	QNetworkReply* reply = manager->get(request);
	QEventLoop loop;
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();
	QByteArray content = reply->readAll();
	return content;
}


//�������� ���, ������� � ���������, ������� � label
void VK::getUserInfo(const QString& _id, QLabel* _label, QLabel* _pixmap) {
	//������ � �������� �� ��������� ��� � ���� ���������
	QString requestStr = QString("https://api.vk.com/method/users.get?user_ids=%1&fields=photo_50&access_token=%2&v=5.103").arg(_id, access_token);
	//����� ������� � �������� �������
	QJsonObject jobj = sendRequest(requestStr);

	//��������� ����� � ������� �� ������ � �������� �� � �����
	QString name("");
	name += jobj["response"].toArray().at(0).toObject()["first_name"].toString();
	_label->setText(name);

	//�������� ����������, �������� ������, ���������� ������ �� ����, ���������� � �������������� �������
	QString photo_50 = jobj["response"].toArray().at(0).toObject()["photo_50"].toString();
	QByteArray content = getPhoto(photo_50);
	QPixmap picture;
	picture.loadFromData(content);
	_pixmap->setPixmap(picture);
}

QList<Followed*> VK::getOnline(QList<Followed*> list) {
	QList<Followed*> online;
	for (ptrdiff_t i(0); i < list.size(); i += 1) {
		QString requestStr = QString("https://api.vk.com/method/users.get?user_ids=%1&fields=online&access_token=%2&v=5.103").
			arg(list.at(i)->id, access_token);
		QJsonObject jobj = sendRequest(requestStr);
		list.at(i)->status = jobj["response"].toArray().at(0).toObject()["online"].toInt();
		qDebug() << "sending request.. " << list.at(i)->id << " " << list.at(i)->status;
		if (list.at(i)->status != 0) {
			online.append(new Followed());
			online.back()->id = list.at(i)->id;
			online.back()->name = list.at(i)->name;
			online.back()->time = list.at(i)->time;
			online.back()->status = list.at(i)->status;
			online.back()->ui->link->setText(online.back()->id);
			online.back()->item->setSizeHint(list.at(i)->sizeHint());
			getUserInfo(online.back()->id, online.back()->ui->name, online.back()->ui->photo);
		}
	}
	return online;
}

void VK::track(QList<Followed*> list) {
	int size = list.size();
	qDebug() << "track";
	QEventLoop loop;
	connect(timer, SIGNAL(timeout()), &loop, SLOT(quit()));
	QList<Followed*> online;
	while (!cancelation && list.size() != 0) {
		timer->start(3000);
		loop.exec();
		if (!cancelation)
			online = getOnline(list);
		if (online.size() != 0) {
			for (ptrdiff_t i(0); i < online.size(); i += 1) {
				for (ptrdiff_t j(0); j < list.size(); j += 1) {
					if (online.at(i)->id == list.at(j)->id) {
						list.removeAt(j);
					}
				}
			}
			emit resultReady(online);

		}
		if (online.size() == size) {
			cancelation = true;
		}
	}
	qDebug() << "cancelation = " << cancelation;
}

