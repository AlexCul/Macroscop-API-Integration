#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <unistd.h>


#include <QFile>
#include <QTextStream>

#include <QDate>
#include <QTime>

#include <QUrl>
#include <QtNetwork/QNetworkReply>


#include "app.h"
#include "ui_app.h"

App::App(QWidget *parent) : QMainWindow(parent), ui(new Ui::App) {
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

App::~App() {
    delete ui;
}

class NotUiFunctions {
    public:
        void journal_writing(QString message) {
            QString username = getlogin();
            QString path = "/home/";
            path.append(username);
            path.append("/Macroscop/Macroscop-API-Integration/MIwAPI/history/journal.txt");
            QFile journal_file(path);
            journal_file.open(QIODevice::ReadWrite | QIODevice::Append);
            QTextStream stream(&journal_file);
            stream << QDate::currentDate().toString() << " " << QTime::currentTime().toString() << ": " << message << ";\n";
        }
};

class UiFunctions : public App {};

#endif // FUNCTIONS_H
