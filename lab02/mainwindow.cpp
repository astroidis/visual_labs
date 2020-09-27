#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QButtonGroup>
#include <QCheckBox>
#include <QList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(on_buttonGroup_clicked(int)));
    ui->checkGroup->setExclusive(false);
    connect(ui->checkGroup, SIGNAL(buttonToggled(QAbstractButton *, bool)),
            this, SLOT(on_checkGroup_clicked()));
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


void MainWindow::on_buttonGroup_clicked(int id)
{
    ui->label_2->setText("Selected option: " + QString::number(-id-1));
}


void MainWindow::on_checkGroup_clicked()
{
    QString text = "Active channels: ";
    QString state;
    QList<QAbstractButton *> checks = ui->checkGroup->buttons();

    for (int i = 0; i < checks.length(); i++)
        if (checks[i]->isChecked())
            state += QString::number(i+1);
        else
            state += "";

    ui->label_3->setText(text + state);
}
