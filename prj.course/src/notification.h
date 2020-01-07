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

    float getOpacity() const;
    void setOpacity(float opacity);
    void enterEvent(QEvent* event);

    Ui::Notification* ui{ nullptr };

protected:
    void paintEvent(QPaintEvent* event);

public slots:
    void setInfo(const QString& name, const QString& time, const QPixmap* photo);
    void show();
    void hide_();

private slots:
    void hideAnimation();

private:
    QPropertyAnimation animation;
    float opacity{ 0 };
    QTimer* timer;
    bool fixed{ false };
};

#endif
