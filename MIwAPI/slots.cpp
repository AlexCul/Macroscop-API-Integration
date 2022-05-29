#include <QFileDialog>


#include "common_functions.h"
#include "full_interface/full_interface.h"
NotUiFunctions notuifuncs;

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

void App::on_translate_btn_clicked() {
    notuifuncs.journal_writing(ui->jsonfilepath_lnedit->text());
    QFile file(ui->jsonfilepath_lnedit->text());
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            ui->answerreader_txtbrowser->setText(file.readAll());
    this->statusBar()->showMessage(ui->jsonfilepath_lnedit->text());
}

void App::on_jsonfilepath_btn_clicked() {
    QString filepath = QFileDialog::getOpenFileName(this, "Open...", "", tr("JSON (*.json)"));
    ui->jsonfilepath_lnedit->setText(filepath);
}

void App::on_sendrequest_btn_clicked() {
    notuifuncs.journal_writing(ui->serverip_lnedit->text());
    request.setUrl(QUrl(ui->serverip_lnedit->text()));
    manager->get(request);
    this->statusBar()->showMessage(ui->serverip_lnedit->text());
}

void App::on_openfullinterface_btn_clicked() {
    FullInterface *full_interface = new FullInterface();
    full_interface->show();
}
