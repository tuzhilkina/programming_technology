//! @file arcore/notification.h
#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QTimer>
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class Notification; }
QT_END_NAMESPACE

class Notification : public QWidget
{
    Q_OBJECT
        Q_PROPERTY(float opacity READ getOpacity WRITE setOpacity)

public:
    explicit Notification(QWidget* parent = nullptr);
    ~Notification();
    //! @brief Возвращает значение прозрачности виджета.
    float getOpacity() const;
    //! @brief Устанавливает прозрачность виджета.
    void setOpacity(float opacity);
    //! @brief Фиксирует, если курсор мыши был наведен на уведомление.
    void enterEvent(QEvent* event);

    Ui::Notification* ui{ nullptr };

protected:
    //! @brief Прорисовка уведомление в нижней правой части экрана.
    void paintEvent(QPaintEvent* event);

public slots:
    //! @brief Отображает ифнормацию о человеке, который появился онлайн.
    void setInfo(const QString& name, const QString& time, const QPixmap* photo);
    //! @brief Отображает уведомление.
    void show();
    //! @brief Скрывает уведомление через анимацию.
    void hide_();

private slots:
    //! @brief Запуск анимированного скрытия уведомления.
    void hideAnimation();

private:
    QPropertyAnimation animation; //!< Анимация.
    float opacity{ 0 };  //!< Прозрачность уведомления.
    QTimer* timer;  //!< Таймер для скрытия уведомления.
    bool fixed{ false };   //!< Флаг, был ли наведен курсор мыши.
};

#endif
