#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>

QT_BEGIN_NAMESPACE
namespace Ui { class App; }
QT_END_NAMESPACE

class App : public QMainWindow
{
    Q_OBJECT

public:
    App(QWidget *parent = nullptr);
    ~App();

private slots:
    void on_translate_btn_clicked();

    void on_jsonfilepath_btn_clicked();

    void on_sendrequest_btn_clicked();

private:
    Ui::App *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
};
#endif // APP_H
