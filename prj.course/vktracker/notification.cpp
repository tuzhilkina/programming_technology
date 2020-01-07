#include "notification.h"
#include "ui_notification.h"
#include <QPainter>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

Notification::Notification(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Notification)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint |
        Qt::Tool |
        Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);

    animation.setTargetObject(this);
    animation.setPropertyName("opacity");
    connect(&animation, &QAbstractAnimation::finished, this, &Notification::hide_);
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));


    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &Notification::hideAnimation);

    QIcon toClose("/vktracker/close.png");
    ui->close->setIcon(toClose);
}

Notification::~Notification() {
    qDebug() << "nb nokndf";
    delete ui;
    delete timer;
}

void Notification::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event)
        QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); 
    QRect roundedRect;
    roundedRect.setX(rect().x() + 5);
    roundedRect.setY(rect().y() + 5);
    roundedRect.setWidth(rect().width() - 10);
    roundedRect.setHeight(rect().height() - 10);
    painter.setBrush(QBrush(QColor(40, 40, 40, 220)));
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(roundedRect, 6, 6);
}

void Notification::setInfo(const QString& name, const QString& time, const QPixmap* photo) {
    QPixmap p(*photo);
    ui->name->setText(name);
    ui->online_at->setText(time);
    ui->photo->setPixmap(p);
}

void Notification::show() {
    setWindowOpacity(0.0);
    animation.setDuration(300);
    animation.setStartValue(0.0);
    animation.setEndValue(1.0);

    setGeometry(QApplication::desktop()->availableGeometry().width() - 36 - width() + QApplication::desktop()->availableGeometry().x(),
        QApplication::desktop()->availableGeometry().height() - 36 - height() + QApplication::desktop()->availableGeometry().y(),
        width(),
        height());
    QWidget::show();

    animation.start();
    timer->start(7000);
}

void Notification::hideAnimation() {
    timer->stop();
    if (!fixed) {
        animation.setDuration(300);
        animation.setStartValue(1.0);
        animation.setEndValue(0.0);
        animation.start();
    }
}

void Notification::hide_() {
    if (opacity == 0.0) {
        QWidget::close();
    }
}

void Notification::setOpacity(float opacity_) {
    opacity = opacity_;
    setWindowOpacity(opacity);
}


float Notification::getOpacity() const {
    return opacity;
}

void Notification::enterEvent(QEvent* event) {
    fixed = true;
}