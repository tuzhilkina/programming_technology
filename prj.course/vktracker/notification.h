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
    //! @brief ���������� �������� ������������ �������.
    float getOpacity() const;
    //! @brief ������������� ������������ �������.
    void setOpacity(float opacity);
    //! @brief ���������, ���� ������ ���� ��� ������� �� �����������.
    void enterEvent(QEvent* event);

    Ui::Notification* ui{ nullptr };

protected:
    //! @brief ���������� ����������� � ������ ������ ����� ������.
    void paintEvent(QPaintEvent* event);

public slots:
    //! @brief ���������� ���������� � ��������, ������� �������� ������.
    void setInfo(const QString& name, const QString& time, const QPixmap* photo);
    //! @brief ���������� �����������.
    void show();
    //! @brief �������� ����������� ����� ��������.
    void hide_();

private slots:
    //! @brief ������ �������������� ������� �����������.
    void hideAnimation();

private:
    QPropertyAnimation animation; //!< ��������.
    float opacity{ 0 };  //!< ������������ �����������.
    QTimer* timer;  //!< ������ ��� ������� �����������.
    bool fixed{ false };   //!< ����, ��� �� ������� ������ ����.
};

#endif
