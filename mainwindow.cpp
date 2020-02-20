#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QList>

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
    // Получение названия открываемого файла.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "/home");
    // Создание объекта "Файл".
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    // Создаём входящий поток, из которого будут считываться данные, и связываем его с нашим файлом.
    QTextStream in(&file);
    QString line;
    // Считываем файл строка за строкой.
    while (!in.atEnd()) { // метод atEnd() возвращает true, если в потоке больше нет данных для чтения.
        line = in.readLine(); // метод readLine() считывает одну строку из потока.
        ui->textEdit->setText(ui->textEdit->toPlainText()+line+"\n");
    }
    file.close();// Закрываем файл.
}

void MainWindow::textMove(const QString &text)
{
   // ui->label->setText(text);
}
