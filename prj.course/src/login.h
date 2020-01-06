#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

#include <QWebEngineView>
#include <QWebEnginePage>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr);
    ~Login();

    QString URL{ "https://oauth.vk.com/authorize?client_id=7219750&redirect_uri=https://oauth.vk.com/blank.html&scope=notify,offline&response_type=token&v=5.103" };
    QString access_token{ "" };
    QString user_id{ "" };

signals:
    void closed();


private slots:
    void getInfo(QUrl);
private:
    Ui::Login* ui{ nullptr };
};

#endif