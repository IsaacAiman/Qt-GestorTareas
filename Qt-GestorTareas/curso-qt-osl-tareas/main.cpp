#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QCoreApplication::setOrganizationName("ULL");
    QCoreApplication::setOrganizationDomain("ull.es");
    QCoreApplication::setApplicationName("GestorTareas");

    w.show();

    return a.exec();
}
