#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringList>
#include <QStandardItem>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QStandardItemModel(10, 13))
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
    for (int i = 2000; i < 2011; i++)
    {
        hheader.append(QString("%1").arg(i));
    }
    hheader.append("Average");
    hheader.append("Variance");
    model->setHorizontalHeaderLabels(hheader);

    QStringList vheader;
    for (int i = 1; i < 11; i++)
    {
        vheader.append(QString("%1").arg(i));
    }
    model->setVerticalHeaderLabels(vheader);

    ui->tableView->setModel(model);
}

double average(QList<double> nums)
{
    double sum = 0;
    for(double x: nums)
    {
        sum += x;
    }
    return sum / (double) nums.size();
}

double variance(QList<double> nums)
{
    double avg = average(nums);
    double sum = 0;
    for (double x: nums)
    {
        sum += std::pow(x - avg, 2);
    }
    return std::sqrt(sum / (double) nums.size());
}

void MainWindow::calcTable()
{
    int rows = model->rowCount();
    int cols = model->columnCount()-2;
    for (int i = 0; i < rows; i++)
    {
        QList<double> arr;
        for (int j = 0; j < cols; j++)
        {
            QModelIndex ind = model->index(i, j);
            double item = model->data(ind).toDouble();
            arr.push_back(item);
        }
        double avg = average(arr);
        double var = variance(arr);
        model->setItem(i, cols, new QStandardItem(QString("%1").arg(avg, 0, 'g', 3)));
        model->setItem(i, cols+1, new QStandardItem(QString("%1").arg(var, 0, 'g', 3)));
    }
}
