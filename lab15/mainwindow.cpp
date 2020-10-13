#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QtCharts>

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , lineSeries(new QLineSeries())
{
    ui->setupUi(this);
    connect(ui->actionCalculate, &QAction::triggered,
            this, &MainWindow::tabulateFunction);
    connect(ui->actionPlot, &QAction::triggered,
            this, &MainWindow::plotLineChart);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::tabulateFunction()
{
    lineSeries->clear();

    double start = ui->leftBoundEdit->text().toDouble();
    double stop = ui->rightBoundEdit->text().toDouble();
    double step = ui->stepEdit->text().toDouble();

    QPlainTextEdit *output = ui->screenOutputText;
    output->moveCursor(QTextCursor::End);
    output->insertPlainText("X\tF(X)\n");

    double x = start, y = 36000 / (1821.6 * x);
    double min = y, max = y;
    while (x <= stop + step/2){
        y = 36000 / (1821.6 * x);
        if (y > max){
            max = y;
        }
        if (y < min){
            min = y;
        }
        if (ui->screenOutputCheck->isChecked()){
            output->insertPlainText(QString("%1\t%2\n").arg(x, 8, 'f', 3).arg(y, 8, 'f', 3));
        }
        if (ui->arrayOutputCheck->isChecked()){
            lineSeries->append(x, y);
        }
        x += step;
    }
    output->insertPlainText(QString("min = %1 max = %2\n").arg(min, 8, 'f', 3).arg(max, 8, 'f', 3));
}


void MainWindow::plotLineChart()
{
    QChart *lineChart = new QChart();
    lineChart->legend()->hide();
    lineChart->addSeries(lineSeries);
    lineChart->createDefaultAxes();

    QChartView *chartView = new QChartView(lineChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->chartLayout->addWidget(chartView);
    resize(800, 400);
}
