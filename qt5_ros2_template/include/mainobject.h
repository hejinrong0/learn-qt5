#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include <QObject>
#include "mainwindow.h"

class MainWindow;

class MainObject : public QObject
{
    Q_OBJECT
public:
    explicit MainObject(QObject *parent = 0);
    ~MainObject();
public:
    void setInit();

private:
    MainWindow *m_mainWindow;
};

#endif // MAINOBJECT_H
