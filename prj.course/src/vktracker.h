#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_vktracker.h"
#include "login.h"
#include "vk.h"
#include "followed.h"
#include "ui_followed.h"

#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QSound>
#include <QSettings>
#include <QVariant>


QT_BEGIN_NAMESPACE
namespace Ui { class vktracker; }
QT_END_NAMESPACE

class vktracker : public QMainWindow
{
	Q_OBJECT

public:
	vktracker(QWidget* parent = nullptr);
	~vktracker();

private slots:
	//нажатие кнопки войти инициирует вызов браузера
	void slotLogin();
	//нажатие кнопки выйти прекращает отслеживание всех людей и уничтожает токен
	void slotLogout();
	//ввод id и нажатие enter начинает отслеживание нового списка лиц
	void addLink();
	//когда человек заходит в онлайн
	void showNotification(QList<Followed*>);

	void stopFollowing(QListWidgetItem*);

	void closeNotification(QListWidgetItem*);

	void stopAll();

	void loadID();

private:
	Ui::vktracker* ui{ nullptr };
	VK vk;
	//список людей, которые нужно отслеживать
	QList<Followed*> list;
	QList<Followed*> online;
	void saveSettings();
	QString loadSettings();
};
