//
// Created by Владислав Отвагин on 06.10.2024.
//

#include "mainwindow.h"

#include "modeling.h"

mainwindow::mainwindow(std::string s) {
    this->setFixedWidth(1000);
    this->setFixedHeight(700);
    start = new QPushButton(this);
    start->setText("Start");
    mainwindow::setbeer(s);
    start->setGeometry(QRect(400, 300, 200, 70));
    start->setStyleSheet("background-color: rgb(150, 1, 200); "
                         "border-radius: 10px;");
    start->show();
    beerButton = new QPushButton(this);
    beerButton->setGeometry(QRect(800, 500, 100, 100));
    beerButton->setStyleSheet("background-color: rgba(255, 255, 255, 0); ");
    beer_timer = new QTimer(this);
    beer_timer->setInterval(100);
    connect(start, &QPushButton::clicked, this, &mainwindow::start_press);
    connect(beerButton, &QPushButton::clicked, this, &mainwindow::beer_press);
    connect(beer_timer, &QTimer::timeout, this, &mainwindow::beer_update);
}

void mainwindow::setbeer(std::string s) {
    std::string model = "model";
    int cnt = 0;
    bool is = 0;
    for(int i = 0; i < s.size()-5; ++i) {
        if(s[i] == 'm'){
            for(int j = 0; j < 5; ++j) {
                if(s[j+i] == model[j]) {
                    cnt = i + j;
                    if(j == 4) {
                        is = 1;
                        break;
                    }
                }
            }
            if(is)break;
        }if(is) break;
    }
    model = "";
    for(int i =0; i <= cnt; ++i ) {
        model += s[i];
    }
    s = model;
    this->put = s;
    QLabel *beer;
    beer = new QLabel(this);
    beer->setGeometry(QRect(800, 500, 100, 100));
    QString f = QString::fromStdString(s+ "/images/beer.png");
    QPixmap *pix = new QPixmap(f);
    beer->setPixmap(*pix);
}

void mainwindow::start_press() {
    modeling * mod = new modeling();
    mod->show();
    this->hide();
}

void mainwindow::beer_press() {
    beer_timer->start();
}

void mainwindow::beer_update() {
    QLabel *beer;
    beer = new QLabel(this);
    beer->setGeometry(QRect(beer_curr_i, beer_curr_j, 100, 100));
    QString f = QString::fromStdString(this->put + "/images/beer.png");
    QPixmap *pix = new QPixmap(f);
    beer->setPixmap(*pix);
    beer->show();
    beer_curr_i+=150;
    beer_curr_j+=(beer_curr_i > 1000 ? 150: 0);
    if(beer_curr_i > 1000) beer_curr_i = 0;
    if(beer_curr_j > 700) beer_timer->stop();
}