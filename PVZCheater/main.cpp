#include "PVZCheater.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PVZCheater w;
    w.show();
    return a.exec();
}
