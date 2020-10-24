#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <QtCharts>

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , series1 (new QLineSeries())
    , series2 (new QLineSeries())
    , series3 (new QLineSeries())
{
    ui->setupUi(this);
    connect(ui->calcButton, &QPushButton::clicked, this, &MainWindow::plotChart);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcSeries(){
    double x, y, h, stop = 16;
    for (x = 8, h = 0.1; x < stop + h/2; x+=h){
        y = 2.5 * std::pow(1.08, x);
        series1->append(x, y);

        y = 5.7 * std::pow(1.095, x);
        series2->append(x, y);

        series3->append(x, y+5.45);
    }
}

void MainWindow::plotChart(){
    calcSeries();

    series1->setName("Y = 2.5 * (1 + 0.08)^X");
    series2->setName("Y = 5.7 * (1 + 0.095)^X");
    series3->setName("Y = 5.7 * (1 + 0.095)^X + 5.45");

    QChart *chart = new QChart();
    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->addSeries(series3);

    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).back()->setTitleText("X");
    chart->axes(Qt::Vertical).back()->setTitleText("Y");
    chart->legend()->setVisible(true);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->chartLayout->addWidget(chartView);
}
