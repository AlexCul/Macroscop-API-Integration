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
#include "ui_design.h"


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


#endif // FUNCTIONS_H
