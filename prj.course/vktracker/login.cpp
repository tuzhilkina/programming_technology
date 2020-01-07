#include "login.h"
#include "ui_login.h"
#include <QUrlQuery>

Login::Login(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);
    //�������� �������� ����� ��
    ui->webEngineView->load(QUrl(URL));

    //����� ��������� ���������� ������� �������������� �� �������� � �������, ������� ���� ��������
    connect(ui->webEngineView, SIGNAL(urlChanged(QUrl)),this, SLOT(getInfo(QUrl)));
}

Login::~Login() {
    delete ui;
}

void Login::getInfo(QUrl url) {
    url = url.toString().replace("#", "?");
    QUrlQuery query(url);
    access_token = query.queryItemValue("access_token");
    user_id = query.queryItemValue("user_id");
    if (user_id != "")
        close();
}