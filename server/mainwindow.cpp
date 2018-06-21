#include "mainwindow.h"
#include "ui_mainwindow.h"



class QStandardItemModel;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->removeToolBar(ui->mainToolBar);

    ui->statusBar->showMessage(tr("当前在线人数: 5"));
    ui->tabWidget->setTabText(0, "概览");
    ui->tabWidget->removeTab(1);


    QStandardItemModel *model = new QStandardItemModel();
//    QStandardItem *item1 = new QStandardItem(tr("昵称"));
//    model.setItem(0, 0, item1);


//    QStandardItem *item2 = new QStandardItem(tr("设备"));
//    model.setItem(0, 1, item2);

//    QStandardItem *item3 = new QStandardItem(tr("status"));
//    model.setItem(0, 2, item3);

//    model.setHeaderData(0, Qt::Horizontal, "nick");
//    model.setHeaderData(1, Qt::Horizontal, "device");
//    model.setHeaderData(2, Qt::Horizontal, "state");
    QStringList headerLabels = QObject::trUtf8("昵称,设备,IP").simplified().split(",");
//    headerLabels << tr("昵称") << tr("设备") << QObject.trUtf8("状态");
    model->setHorizontalHeaderLabels(headerLabels);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->showGrid();
    ui->tableView->show();

    socket = new ServerSocket();
    socket->listen(8899);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete socket;
}
