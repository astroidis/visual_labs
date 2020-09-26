#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::closeEvent(QCloseEvent *event){
    QMessageBox msg;
    msg.setWindowTitle("Exit");
    msg.setText("Do you want to exit?");
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int res = msg.exec();

    switch (res) {
    case QMessageBox::Yes:
        event->accept();
        break;
    case QMessageBox::No:
        event->ignore();
        break;
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
    QMessageBox msg;
    msg.setWindowTitle("Clicks");
    msg.setText("Double click not allowed");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
    event->ignore();
}

MainWindow::~MainWindow()
{
    delete ui;
}
