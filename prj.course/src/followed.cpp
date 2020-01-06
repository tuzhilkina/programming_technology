#include "followed.h"


Followed::Followed(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Followed)
{
    ui->setupUi(this);
    item = new QListWidgetItem();
}

Followed::Followed(const Followed& obj)
    : ui(nullptr)
    , name(obj.name)
    , id(obj.id)
    , time(obj.time)
    , status(obj.status)
    , item(nullptr)
{
}

Followed::~Followed() {
    qDebug() << "delete " << id;
    item = nullptr;
    ui = nullptr;
}

