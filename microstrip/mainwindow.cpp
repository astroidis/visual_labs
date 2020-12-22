#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::calculate);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setupMSL()
{
    double eps = ui->epsEdit->text().toDouble();
    double rho = ui->rhoEdit->text().toDouble();
    double h = ui->hEdit->text().toDouble();
    double f = ui->fEdit->text().toDouble();
    double vc = ui->vcEdit->text().toDouble();
    double wh = ui->whEdit->text().toDouble();
    double qf = ui->qfEdit->text().toDouble();

    msl.eps = eps;
    msl.rho = rho;
    msl.f = f;
    msl.h = h;
    msl.w_h = wh;
    msl.v_c = vc;
    msl.qf_norm = qf;
}

void MainWindow::calculate()
{
    setupMSL();
    ui->widthOut->setText(QString("%1").arg(msl.width()));
    ui->e_effOut->setText(QString("%1").arg(msl.epsilon_eff()));
    ui->waveLenOut->setText(QString("%1").arg(msl.waveLength()));
    ui->limFreqOut->setText(QString("%1").arg(msl.limFrequency()));
    ui->qfOut->setText(QString("%1").arg(msl.qfactor()));
    ui->lossOut->setText(QString("%1").arg(msl.conductorLoss()));
}
