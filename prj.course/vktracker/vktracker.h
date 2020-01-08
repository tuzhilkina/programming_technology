//! @file arcore/vktracker.h
#ifndef VKTRACKER_H
#define VKTRACKER_H

#include <QtWidgets/QMainWindow>
#include "ui_vktracker.h"
#include "login.h"
#include "vk.h"
#include "followed.h"
#include "ui_followed.h"
#include "notification.h"

#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QSound>
#include <QSettings>
#include <QVariant>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QCloseEvent>
#include <QTime>
#include <QFile>
#include <QDir>
#include <QStandardPaths>



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
	//! @brief ������� ������ ����� ���������� ����� �������� � �������� ��������� �����.
	void slotLogin();
	//! @brief ������� ������ ����� ���������� ������������ ���� ����� � ���������� �����.
	void slotLogout();
	//! @brief ���� id � ������� enter �������� ������������ ������ ������ ���.
	void addLink();
	//! @brief ����� �����������, ����� ������� ������� � ������.
	void showNotification(QList<Followed*>);
	//! @brief ���������� ������������ �������� ������� ������� ���.
	void stopFollowing(QListWidgetItem*);
	//! @brief ������� ����������� ������� �������� ���.
	void closeNotification(QListWidgetItem*);
	//! @brief ��������� ������ ������������� � ������� ������.
	void loadID();
	//! @brief ���������� ������������ �� ����� ������.
	void stopAll();
	//! @brief ��������� ������� ���������� � ���������� ��� ������. ����������� ����� ����������� ���� � ����.
	void exitApp();
	//! @brief ������� ���� ����������. ����������� ����� ����������� ���� � ����.
	void openApp();
	//! @brief �������� ���� ���������� �� ������ �� ����� ��������� ��� ������.
	void closeEvent(QCloseEvent* event);
	//! @brief ��������� ���� � ������ ����� ����� �������.
	void saveSettings();
	//! @brief ��������� ���� � ������ ����� ����������� ������.
	QString loadSettings();

private:
	Ui::vktracker* ui{ nullptr };
	VK* vk;

	QList<Followed*> list; //!< ������ ����� �������.
	QList<Followed*> online; //!< ������ ����� ������.
	QSystemTrayIcon* tray_icon; //!< ������ ����������.
	QMenu menu; //!< ����������� ���� � ����.
};

#endif