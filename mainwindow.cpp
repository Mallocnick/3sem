#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

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


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "Vladslav Kim ISTAS 2-3" );
}

void MainWindow::on_actionOpen_file_triggered()
{
    //QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "/home");
    //connect(fileName, &QFileDialog::getOpenFileName, this, &MainWindow::textMove);
    ui->label->setText(QFileDialog::getOpenFileName(this, tr("Open file"), "/home"));
    ui->listView


}

void MainWindow::textMove(const QString &text)
{
    ui->label->setText(text);
}
