#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "microstripline.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MicrostripLine msl;

    void setupMSL();

private slots:
    void calculate();
};
#endif // MAINWINDOW_H
