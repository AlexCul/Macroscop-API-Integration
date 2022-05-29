#ifndef FULL_INTERFACE_H
#define FULL_INTERFACE_H

#include <QMainWindow>

namespace Ui {
class FullInterface;
}

class FullInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit FullInterface(QWidget *parent = nullptr);
    ~FullInterface();

private:
    Ui::FullInterface *ui;
};

#endif // FULL_INTERFACE_H
