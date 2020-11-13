#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringList>
#include <QStandardItem>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QStandardItemModel(5, 2))
{
    ui->setupUi(this);
    initTable();
    connect(ui->calcButton, &QPushButton::clicked, this, &MainWindow::calcTable);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTable()
{
    QStringList hheader;
    hheader.append("x");
    hheader.append("cos(x)");
    model->setHorizontalHeaderLabels(hheader);

    QStringList vheader;
    for (int i = 1; i < 6; i++)
    {
        vheader.append(QString("item %1").arg(i));
    }
    model->setVerticalHeaderLabels(vheader);

    model->setItem(0, 0, new QStandardItem(QString("0.2")));
    model->setItem(1, 0, new QStandardItem(QString("0.7")));
    model->setItem(2, 0, new QStandardItem(QString("1.8")));
    model->setItem(3, 0, new QStandardItem(QString("3.1")));
    model->setItem(4, 0, new QStandardItem(QString("4.2")));

    ui->tableView->setModel(model);
}

void MainWindow::calcTable()
{
    for (int i = 0; i < 5; i++)
    {
        QModelIndex ind = model->index(i, 0);
        double item = model->data(ind).toDouble();
        double res = cos(item);
        model->setItem(i, 1, new QStandardItem(QString("%1").arg(res, 0, 'g', 4)));
    }
}
