#include "mainobject.h"
#include "splashscreen.h"

MainObject::MainObject(QObject *parent) :
    QObject(parent)
{

}

MainObject::~MainObject()
{
    delete m_mainWindow;
}

void MainObject::setInit()
{
    SplashScreen::getInstance();
//    m_mainWindow = new MainWindow();

//    m_mainWindow->setWindowTitle(tr("This is template"));
//    m_mainWindow->showNormal();
}
