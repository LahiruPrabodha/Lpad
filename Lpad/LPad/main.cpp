#include "lpad.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LPad w;
    w.show();


    return a.exec();
}
