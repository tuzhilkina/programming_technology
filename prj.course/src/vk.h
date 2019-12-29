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

	//личный токен пользвателя вк, необходимый для запросов
	QString access_token{ "" };
	//id пользователя, от лица которого будут посылаться запросы
	QString user_id{ "" };
	//миниатюра фотографии
	QString photo_50{ "" };

	//получить имя, фамилию и миниатюру, вывести в label
	void getUserInfo(const QString& _id, QLabel* _label, QLabel* _pixmap);

	//получить миниатюру пользователя
	QByteArray getPhoto(const QString&);

	//отправить запрос на сервер вк и получить ответ в читаемом формате
	QJsonObject sendRequest(const QString&);

	//парсинг JSON-объекта из строки ответа сервера
	QJsonObject ObjectFromString(const QString& in);

	QList<Followed*> getOnline(QList<Followed*>);

	void track(QList<Followed*> list);

	bool cancelation{ false };

signals:
	void resultReady(QList<Followed*>);

private:
	//менеджер для отправки запросов на сервер
	QNetworkAccessManager* manager = new QNetworkAccessManager(this);

	QTimer* timer = new QTimer(this);
};
#endif
