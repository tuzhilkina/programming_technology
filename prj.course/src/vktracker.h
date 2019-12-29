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

	void stopAll();

	void loadID();

private:
	Ui::vktracker* ui{ nullptr };
	VK vk;
	//������ �����, ������� ����� �����������
	QList<Followed*> list;
	QList<Followed*> online;
	void saveSettings();
	QString loadSettings();
};
