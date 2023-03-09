#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    process = new QProcess(this);

    if (process->state() == QProcess::Running)
    {
        process->kill();
        process->waitForFinished();
    }
    process->setReadChannel(QProcess::StandardOutput);

    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(on_readOutput()));
    connect(process, SIGNAL(readyReadStandardError()), this, SLOT(on_readError()));

    process->start("ping localhost");

    if (process->waitForStarted()) {
        qDebug() << "ping localhost is starting";
    } else {
        qDebug() << "ping localhost start failed";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_readOutput()
{
    qDebug() << process->readAllStandardOutput();
    ui->textEdit->append(process->readAllStandardOutput().data());
}
void MainWindow::on_readError()
{
    QMessageBox::information(0, "Error", process->readAllStandardError().data());
}
