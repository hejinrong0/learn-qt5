#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->tableWidget = new QTableWidget(12, 3, this);
    // 设置table内容行为10行
    ui->tableWidget->setRowCount(10);
    // 设置table内容的列为7列
    ui->tableWidget->setColumnCount(7);
    // 新增单元格内容
    QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg("item"));
    // setItem(行(从0开始)， 列(从0开始)， 内容)
    ui->tableWidget->setItem(0, 0, newItem);
    // 设置table标题
    QStringList labelItems;
    labelItems << "First" << "Second" << "Third";
    // 设置水平标题
    ui->tableWidget->setHorizontalHeaderLabels(labelItems);
    // 设置垂直标题
    ui->tableWidget->setVerticalHeaderLabels(labelItems);

    // QTableWidgetItem *cubesHeaderItem = new QTableWidgetItem(tr("Cubes"));
    // cubesHeaderItem->setTextAlignment(Qt::AlignVCenter);

    connect(ui->addRowBtn,&QPushButton::clicked,this,&MainWindow::AddRow);
    connect(ui->deleteRow,&QPushButton::clicked,this,&MainWindow::DeleteRow);
    connect(ui->addColumnBtn,&QPushButton::clicked,this,&MainWindow::AddColumn);
    connect(ui->deleteColumn,&QPushButton::clicked,this,&MainWindow::DeleteColumn);
    connect(ui->clearTable,&QPushButton::clicked,this,&MainWindow::ClearTable);
    connect(ui->clearCon,&QPushButton::clicked,this,&MainWindow::ClearContents);
    connect(ui->fillData,&QPushButton::clicked,this,&MainWindow::FillData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    // insertRow(int num) 函数如果不传入数值，则以0为值，向前增加
    /**
     * 1. 获取当前表格的行数
     * 2. 如果当前表格行数为0，则向insertRow()函数传入0，如果大于0则向insertRow()函数传入rowCount; 
     * 如：0 ~ 5 行，获取的rowCount 行的值为：6，也就是表格的总行数。table表格上显示6行数据，插入的数
     * 据的参数从0开始的，也就是说如果需要插入第7行数据，将rowCount的值传入insertRow()函数中即可。
     * 
    */
    int rowCount = ui->tableWidget->rowCount();
    if (rowCount > 0) {
        ui->tableWidget->insertRow(rowCount);
    } else {
        ui->tableWidget->insertRow(0);
    }
    // https://doc.qt.io/qt-5/qtablewidget.html#insertRow
}

void MainWindow::DeleteRow()
{
    int rowCount = ui->tableWidget->rowCount();
    if (rowCount > 0) {
        ui->tableWidget->removeRow(rowCount - 1);
    } else {
        QMessageBox::about(NULL, "提示", "最后一行了！");
    }
    // https://doc.qt.io/qt-5/qtablewidget.html#removeRow
}

void MainWindow::AddColumn()
{
    int columnCount = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(columnCount);
    // https://doc.qt.io/qt-5/qtablewidget.html#insertColumn
}

void MainWindow::DeleteColumn()
{
    int columnCount = ui->tableWidget->columnCount();
    if (columnCount > 0) {
        ui->tableWidget->removeColumn(columnCount - 1);
    } else {
        QMessageBox::about(NULL, "提示", "最后一列了！");
    }
    // https://doc.qt.io/qt-5/qtablewidget.html#removeColumn
}

void MainWindow::ClearTable()
{
    // 清空table表，删除了行标题和列标题
    ui->tableWidget->clear();
    // https://doc.qt.io/qt-5/qtablewidget.html#clear
}

void MainWindow::ClearContents()
{
    // 清空table表中的内容，不会删除行标题 和 列标题
    ui->tableWidget->clearContents();
    // https://doc.qt.io/qt-5/qtablewidget.html#clearContents
}

void MainWindow::FillData()
{
    QTableWidgetItem *widgetItem = 0;
    // 获取当前表格的行数
    int rowCount = ui->tableWidget->rowCount();
    // 获取当前表格的列数
    int columnCount = ui->tableWidget->columnCount();
    // 循环像单元格添加数据
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < columnCount; ++j) {
            widgetItem = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
            ui->tableWidget->setItem(i,j,widgetItem);
        }
    }
}















