#ifndef FOLLOWED_H
#define FOLLOWED_H

#include "ui_followed.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Followed; }
QT_END_NAMESPACE

class Followed : public QWidget
{
    Q_OBJECT

public:
    explicit Followed(QWidget* parent = nullptr);
    Followed(const Followed&);
    ~Followed();

    Ui::Followed* ui{ nullptr };
    QString name{ "" }; //!< Имя пользователя.
    QString id{ "" }; //!< ID пользователя.
    QString time{ "" }; //!< Время, в которое был произведен вход.
    int status{ 0 };  //!< Статус онлайна.
    QListWidgetItem* item{ nullptr }; //!< Указатель на позицию человека в окне со списком отслеживаемых.
};

#endif