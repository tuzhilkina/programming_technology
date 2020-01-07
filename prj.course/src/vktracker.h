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
	//! @brief Нажатие кнопки войти инициирует вызов браузера с открытой страницей входа.
	void slotLogin();
	//! @brief Нажатие кнопки выйти прекращает отслеживание всех людей и уничтожает токен.
	void slotLogout();
	//! @brief Ввод id и нажатие enter начинает отслеживание нового списка лиц.
	void addLink();
	//! @brief Вывод уведомления, когда человек заходит в онлайн.
	void showNotification(QList<Followed*>);
	//! @brief Прекратить отслеживание человека двойным щелчком ЛКМ.
	void stopFollowing(QListWidgetItem*);
	//! @brief Закрыть уведомление двойным щелкчком ЛКМ.
	void closeNotification(QListWidgetItem*);
	//! @brief Загрузить список отслеживаемых в прошлом сеансе.
	void loadID();
	//! @brief Прекратить отслеживание за всеми людьми.
	void stopAll();
	//! @brief Полностью закрыть приложение и прекратить его работу. Выполняется через контекстное меню в трее.
	void exitApp();
	//! @brief Открыть окно приложения. Выполняется через контекстное меню в трее.
	void openApp();
	//! @brief Закрытие окна приложения не влечет за собой остановку его работы.
	void closeEvent(QCloseEvent* event);
	//! @brief Сохранить вход и список людей перед выходом.
	void saveSettings();
	//! @brief Загрузить вход и список людей предыдущего сеанса.
	QString loadSettings();

private:
	Ui::vktracker* ui{ nullptr };
	VK* vk;

	QList<Followed*> list; //!< Список людей оффлайн.
	QList<Followed*> online; //!< Список людей онлайн.
	QSystemTrayIcon* tray_icon; //!< Иконка приложения.
	QMenu menu; //!< Контекстное меню в трее.
};

#endif