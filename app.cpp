#include <QFile>
#include <QFileDialog>
#include <QTextStream>

#include <QUrl>
#include <QDebug>
#include <QEventLoop>
#include <QByteArray>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>


#include "app.h"
#include "ui_app.h"


App::App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager();
        QObject::connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

                QString answer = reply->readAll();

                ui->answerreader_txtbrowser->setText(answer);
            }
    );
}

App::~App()
{
    delete ui;
}


void App::on_translate_btn_clicked()
{
    QFile file(ui->jsonfilepath_lnedit->text());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    ui->answerreader_txtbrowser->setText(file.readAll());
}

void App::on_jsonfilepath_btn_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Open...", "", tr("JSON (*.json)"));
    ui->jsonfilepath_lnedit->setText(filepath);
}

void App::on_sendrequest_btn_clicked()
{
    request.setUrl(QUrl(ui->serverip_lnedit->text()));
    manager->get(request);
}
