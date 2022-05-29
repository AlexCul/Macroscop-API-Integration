#include "full_interface.h"
#include "ui_full_interface.h"

FullInterface::FullInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FullInterface)
{
    ui->setupUi(this);
}

FullInterface::~FullInterface()
{
    delete ui;
}
