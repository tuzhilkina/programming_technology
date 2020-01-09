#include "followed.h"


Followed::Followed(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Followed) 
{
    ui->setupUi(this);
    item = new QListWidgetItem();
}

Followed::Followed(const Followed& obj)
    : ui(obj.ui)
    , name(obj.name)
    , id(obj.id)
    , time(obj.time)
    , status(obj.status)
    , item(obj.item)
{
}

Followed::~Followed() {
    qDebug() << id;
    item = nullptr;
    ui = nullptr;
}

