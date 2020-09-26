#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn1_clicked()
{
    this->setWindowTitle("Window Title set by Button 1");
}


void MainWindow::on_btn2_clicked()
{
    this->setWindowTitle("Window Title set by Button 2");
}


void MainWindow::on_btn3_clicked()
{
    this->setWindowTitle("Window Title set by Button 3");
}


void MainWindow::on_btn4_clicked()
{
    this->setWindowTitle("Window Title set by Button 4");
}

void MainWindow::on_msgBtn_clicked()
{
    ui->label->setText("Message From Button");
}

void MainWindow::on_enableBtn_clicked()
{
    ui->msgBtn->setEnabled(true);
    ui->label->setText("Button enabled");
}

void MainWindow::on_disableBtn_clicked()
{
    ui->msgBtn->setEnabled(false);
    ui->label->setText("Button disabled");
}
