#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    // Каждое Qt5-приложение (за исключением консольных) должно включать следующую строчку
    QApplication a(argc, argv);
    MainWindow w;
    w.setToolTip("Coursework"); // устанавливаем всплывающую подсказку для виджета
    w.setWindowIcon(QIcon("C:/Users/vladi/Documents/3sem/steamicon.png"));
    w.show(); // выводим на экране
    return a.exec();
}
