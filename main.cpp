//
// Created by Дмитрий Фоминых on 06.10.2024.
//

#include "iostream"
#include <QApplication>
#include "mainwindow.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return QApplication::exec();
}
