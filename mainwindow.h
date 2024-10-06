//
// Created by Владислав Отвагин on 06.10.2024.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
class mainwindow : public QMainWindow{
public:
    mainwindow(std::string s) ;
    void setbeer(std::string s) ;
private:
    QPushButton *start;
    std::string put;
};



#endif //MAINWINDOW_H
