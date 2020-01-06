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
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QThread>


QT_BEGIN_NAMESPACE
namespace Ui { class vktracker; }
QT_END_NAMESPACE

class vktracker : public QMainWindow
{
	Q_OBJECT
		//QThread vkThread;
public:
	vktracker(QWidget* parent = nullptr);
	~vktracker();

	void closeEvent(QCloseEvent* event);

private slots:
	//������� ������ ����� ���������� ����� ��������
	void slotLogin();
	//������� ������ ����� ���������� ������������ ���� ����� � ���������� �����
	void slotLogout();
	//���� id � ������� enter �������� ������������ ������ ������ ���
	void addLink();
	//����� ������� ������� � ������
	void showNotification(QList<Followed*>);

	void stopFollowing(QListWidgetItem*);

	void closeNotification(QListWidgetItem*);

	void loadID();

	void stopAll();

signals:
	void startTracking(QList<Followed*>);

	void cancelTracking();

private:
	Ui::vktracker* ui{ nullptr };
	VK* vk;
	//������ �����, ������� ����� �����������
	QList<Followed*> list;
	QList<Followed*> online;
	void saveSettings();
	QString loadSettings();
	QSystemTrayIcon* tray_icon;
};
