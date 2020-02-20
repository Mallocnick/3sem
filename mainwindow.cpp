#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

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

void MainWindow::on_actionOpen_file_triggered() // read file
{
    //Получение названия открываемого файла.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "/home");
    //Создание объекта "Файл".
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        ui->textEdit->setText(ui->textEdit->toPlainText()+line+"\n");
    }

}

void MainWindow::textMove(const QString &text)
{
   // ui->label->setText(text);
}
