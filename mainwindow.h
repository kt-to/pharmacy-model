//
// Created by Владислав Отвагин on 06.10.2024.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QTimer>
class mainwindow : public QMainWindow{
public:
    mainwindow(std::string s) ;
    void setbeer(std::string s) ;
    void start_press();
    void beer_press();
    void beer_update();
private:
    QPushButton *start = 0;
    QPushButton *beerButton = 0;
    std::string put ;
    QTimer * beer_timer;
    int beer_curr_i = 0;
    int beer_curr_j = 0;
    int beer = 0;
};




#endif //MAINWINDOW_H
