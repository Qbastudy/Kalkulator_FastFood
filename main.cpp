#include "glowna.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Glowna w;
    w.show();
    return a.exec();
}
