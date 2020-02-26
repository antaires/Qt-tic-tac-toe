#include "qt_graphics.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qt_graphics w;
    w.show();
    return a.exec();
}
