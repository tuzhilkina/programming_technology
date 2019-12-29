#include "followed.h"


Followed::Followed(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Followed)
{
    ui->setupUi(this);
    item = new QListWidgetItem();
}

