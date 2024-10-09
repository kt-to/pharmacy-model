//
// Created by Дмитрий Фоминых on 06.10.2024.
//

#include "iostream"
#include <QApplication>
#include "mainwindow.h"

#include "person.h"

int main(int argc, char* argv[])
{
//    QApplication a(argc, argv);
//    std::string s = *argv;
//    mainwindow w(s);
//    w.show();


    std::vector<medicament> all(40);
    for (auto & i : all) {
        i.print();

//    return QApplication::exec();


}
