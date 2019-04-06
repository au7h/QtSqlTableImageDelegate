#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imgdelegate.h"
#include "dbmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    imgDelegate(new ImgDelegate(this))
{
    ui->setupUi(this);
    dbManager.InitDb("QMYSQL", "localhost", "testuser", "password", "zadanie");
    dbManager.dbOpen();
    dbManager.dbSelectAll("Studenci");

    ui->tableView->setModel(dbManager.getTableModel());
    ui->tableView->setItemDelegate(imgDelegate);
    ui->tableView->resizeRowsToContents();
}

MainWindow::~MainWindow()
{
    dbManager.dbClose();
    delete imgDelegate;
    delete ui;
}
