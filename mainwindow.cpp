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
    int id = QFontDatabase::addApplicationFont(QString::fromStdString(put) + "/images/Drabina/Drabina-Solid.otf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont monospace(family);
    monospace.setPixelSize(40);
    start->setGeometry(QRect(400, 300, 200, 70));
    start->setStyleSheet("background-color: rgb(150, 1, 200); "
                         "border-radius: 10px;");
    start->show();
    start->setFont(monospace);

    beerButton = new QPushButton(this);
    beerButton->setGeometry(QRect(800, 500, 100, 100));
    beerButton->setStyleSheet("background-color: rgba(255, 255, 255, 0); ");
    beer_timer = new QTimer(this);
    beer_timer->setInterval(15);
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
    modeling * mod = new modeling(QString::fromStdString(put));
    mod->show();
    this->hide();
}

void mainwindow::beer_press() {
    ++beer;
    beer%=3;
    beer_timer->start();
    beer_curr_i = 0+(beer==2 ? 30 : 0);
    beer_curr_j = 0;
}

void mainwindow::beer_update() {
    if(beer == 1){
        QLabel *beer;
        beer = new QLabel(this);
        beer->setGeometry(QRect(beer_curr_i, beer_curr_j, 100, 100));
        QString f = QString::fromStdString(this->put + "/images/beer.png");
        QPixmap *pix = new QPixmap(f);
        beer->setPixmap(*pix);
        beer->show();
        beer_curr_i+=150;
        beer_curr_j+=(beer_curr_i > 1000 ? 110: 0);
        if(beer_curr_i > 1000) beer_curr_i = 0;
        if(beer_curr_j > 700) beer_timer->stop();
    } else if(beer == 2){
        QLabel *beer;
        beer = new QLabel(this);
        beer->setGeometry(QRect(beer_curr_i, beer_curr_j, 80, 100));

        QString f = QString::fromStdString(this->put + "/images/vodka.png");
        QPixmap *pix = new QPixmap(f);
        beer->setPixmap(*pix);
        beer->show();
        beer_curr_i+=150;
        beer_curr_j+=(beer_curr_i > 1000 ? 110: 0);
        if(beer_curr_i > 1000) beer_curr_i = 30;
        if(beer_curr_j > 700) beer_timer->stop();
    } else {
        QLabel *beer;
        beer = new QLabel(this);
        beer->setGeometry(QRect(beer_curr_i, beer_curr_j, 79, 100));

        QString f = QString::fromStdString(this->put + "/images/zakuson.png");
        QPixmap *pix = new QPixmap(f);
        beer->setPixmap(*pix);
        beer->show();
        beer_curr_i+=150;
        beer_curr_j+=(beer_curr_i > 1000 ? 110: 0);
        if(beer_curr_i > 1000) beer_curr_i = 0;
        if(beer_curr_j > 700) beer_timer->stop();
    }


}