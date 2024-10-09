//
// Created by Дмитрий Фоминых on 06.10.2024.
//

#include "iostream"
#include <QApplication>
#include "mainwindow.h"
#include "back.h"
#include "medicament.h"

#include "person.h"

int main(int argc, char* argv[])
{
//    QApplication a(argc, argv);
//    std::string s = *argv;
//    mainwindow w(s);
//    w.show();

    std::vector<person> all(40);
    for (auto & to : all) {
        to.print();
    }

//    return QApplication::exec();


}
