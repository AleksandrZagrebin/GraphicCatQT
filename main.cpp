#include <QApplication>
#include "cat.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cat w;
    w.show();
    return a.exec();
}