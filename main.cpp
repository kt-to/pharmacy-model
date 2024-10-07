//
// Created by Дмитрий Фоминых on 06.10.2024.
//

#include "iostream"
#include <QApplication>
#include "mainwindow.h"

#include "person.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    std::string s = *argv;
    mainwindow w(s);
    w.show();

    for (int i = 0; i < 10; i++) {
        auto now = new person;
        now->print();
    }

    return QApplication::exec();


}
