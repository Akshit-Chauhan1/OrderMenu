#include "FxOrderList.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CFxOrderList w;
    w.show();
    return a.exec();
}
