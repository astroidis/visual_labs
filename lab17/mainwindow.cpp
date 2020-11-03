#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fileName()
{
    ui->setupUi(this);
    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::openFile);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::saveFile);
    connect(ui->saveasButton, &QPushButton::clicked, this, &MainWindow::saveFileAs);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openFile(){
    fileName = QFileDialog::getOpenFileName(this, "Open", "C:\\",
                                                    "Text (*.txt) ;; All files (*.*)");
    this->setWindowTitle(fileName);
    QFile file(fileName);
    ui->plainTextEdit->clear();
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    ui->plainTextEdit->setPlainText(file.readAll());
    file.close();
}

void MainWindow::saveFile(){
    if (fileName.isEmpty()){
        MainWindow::saveFileAs();
    }
    else{
        QFile file(fileName);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << ui->plainTextEdit->toPlainText();
        file.close();
        this->setWindowTitle(fileName);
    }
}

void MainWindow::saveFileAs(){
    fileName = QFileDialog::getSaveFileName(this, "Save", "C:\\",
                                                    "Text (*.txt) ;; All files (*.*)");
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << ui->plainTextEdit->toPlainText();
    file.close();
    this->setWindowTitle(fileName);
}
