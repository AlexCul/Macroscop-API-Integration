#include <QApplication>


#include "app.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    App window;
    window.show();
    return app.exec();
}
