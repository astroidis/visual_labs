#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->salaryLbl->setVisible(false);
    ui->artImgDescr->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

