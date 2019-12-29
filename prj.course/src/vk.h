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
	VK(const VK&) = default;
	VK& operator=(const VK&) = default;

	//������ ����� ����������� ��, ����������� ��� ��������
	QString access_token{ "" };
	//id ������������, �� ���� �������� ����� ���������� �������
	QString user_id{ "" };
	//��������� ����������
	QString photo_50{ "" };

	//�������� ���, ������� � ���������, ������� � label
	void getUserInfo(const QString& _id, QLabel* _label, QLabel* _pixmap);

	//�������� ��������� ������������
	QByteArray getPhoto(const QString&);

	//��������� ������ �� ������ �� � �������� ����� � �������� �������
	QJsonObject sendRequest(const QString&);

	//������� JSON-������� �� ������ ������ �������
	QJsonObject ObjectFromString(const QString& in);

	QList<Followed*> getOnline(QList<Followed*>);

	void track(QList<Followed*> list);

	bool cancelation{ false };

signals:
	void resultReady(QList<Followed*>);

private:
	//�������� ��� �������� �������� �� ������
	QNetworkAccessManager* manager = new QNetworkAccessManager(this);

	QTimer* timer = new QTimer(this);
};
#endif
