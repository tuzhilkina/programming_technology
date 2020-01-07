//! @file arcore/vk.h
#ifndef VK_H
#define VK_H

#include "followed.h"
#include <QObject>
#include <QLabel>
#include <QPixMap>
#include <QListWidget>
#include <QList>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include <QEventLoop>

#include <QTimer>

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonArray>




class VK : public QObject
{
	Q_OBJECT

public:
	VK(QObject* parent = Q_NULLPTR);
	~VK();

	//!< ������ ����� ������������, �� ���� �������� ������ ������� ������� �� ������ vk.com.
	QString access_token{ "" };
	//!< id ������������, ������������ ����.
	QString user_id{ "" };
	//!< id ��������� ����������.
	QString photo_50{ "" };
	//!< id ������� ���������� ������������.
	bool cancelation{ false };

	//! @brief �������� ���, ������� � ���������, ������� � label.
	void getUserInfo(const QString& _id, QLabel* _label, QLabel* _pixmap);
	//! @brief �������� ��������� ������������.
	QByteArray getPhoto(const QString&);
	//! @brief ��������� ������ �� ������ �� � �������� ����� � �������� �������.
	QJsonObject sendRequest(const QString&);
	//! @brief ������� JSON-������� �� ������ ������ �������.
	QJsonObject ObjectFromString(const QString& in);
	//! @brief ������ ������ ������� �������� �� ������ �������������.
	QList<Followed*> getOnline(QList<Followed*>);
	//! @brief ����� ���������� ������� �������� ������ ����� ������ � ���������� ������ ����� ������ ��� ������ �����������.
	void track(QList<Followed*> list);


signals:
	//! @brief ������, ��� ���� ���� ������ � ���� ������� �����������.
	void resultReady(QList<Followed*>);

private:
	//!< �������� ��� �������� �������� �� ������.
	QNetworkAccessManager* manager = new QNetworkAccessManager(this);
	//!< ������.
	QTimer* timer = new QTimer(this);
};
#endif
