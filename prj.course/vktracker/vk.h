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

	//!< Личный токен пользователя, от лица которого должны вестись запросы на сервер vk.com.
	QString access_token{ "" };
	//!< id пользователя, выполнившего вход.
	QString user_id{ "" };
	//!< id Миниатюра фотографии.
	QString photo_50{ "" };
	//!< id Признак прекратить отслеживание.
	bool cancelation{ false };

	//! @brief Получить имя, фамилию и миниатюру, вывести в label.
	void getUserInfo(const QString& _id, QLabel* _label, QLabel* _pixmap);
	//! @brief Получить миниатюру пользователя.
	QByteArray getPhoto(const QString&);
	//! @brief Отправить запрос на сервер вк и получить ответ в читаемом формате.
	QJsonObject sendRequest(const QString&);
	//! @brief Парсинг JSON-объекта из строки ответа сервера.
	QJsonObject ObjectFromString(const QString& in);
	//! @brief Узнать статус кажолго человека из списка отслеживаемых.
	QList<Followed*> getOnline(QList<Followed*>);
	//! @brief Через промежутки времени получать список людей онлайн и отправлять список людей онлайн для вывода уведомлений.
	void track(QList<Followed*> list);


signals:
	//! @brief Сигнал, что есть люди онлайн и надо вывести уведомление.
	void resultReady(QList<Followed*>);

private:
	//!< Менеджер для отправки запросов на сервер.
	QNetworkAccessManager* manager = new QNetworkAccessManager(this);
	//!< Таймер.
	QTimer* timer = new QTimer(this);
};
#endif
