#ifndef FOLLOWED_H
#define FOLLOWED_H

#include "ui_followed.h"
#include <QWidget>
#include <QListWidgetItem>
#include "ui_followed.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Followed; }
QT_END_NAMESPACE

class Followed : public QWidget
{
    Q_OBJECT

public:
    explicit Followed(QWidget* parent = nullptr);
    ~Followed() = default;

    Ui::Followed* ui{ nullptr };
    QString name{ "" };
    QString id{ "" };
    QString time{ "" };
    int status{ 0 };
    QListWidgetItem* item{ nullptr };
};

#endif