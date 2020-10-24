#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void plotChart();

private:
    Ui::MainWindow *ui;
    QtCharts::QLineSeries *series1, *series2, *series3;

    void calcSeries();
};
#endif // MAINWINDOW_H
