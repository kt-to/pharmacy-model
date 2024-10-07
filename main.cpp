//
// Created by Дмитрий Фоминых on 06.10.2024.
//

#include "iostream"
#include <QApplication>
#include "mainwindow.h"
int main(int argc, char* argv[])
{
    // std::cout << "hello world";
    QApplication a(argc, argv);
    std::string s = *argv;
    mainwindow w(s);
    w.show();
    return QApplication::exec();
}
