#include "mainwindow.h"

#include <QApplication>

#include "mainobject.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
//     MainWindow w;
//     w.show();
    MainObject mainObject;
    mainObject.setInit();

    return a.exec();
}
