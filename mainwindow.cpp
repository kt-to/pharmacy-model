//
// Created by Владислав Отвагин on 06.10.2024.
//

#include "mainwindow.h"

mainwindow::mainwindow(std::string s) {
    this->setFixedWidth(1000);
    this->setFixedHeight(700);
    start = new QPushButton(this);
    start->setText("Start");
    mainwindow::setbeer(s);
    start->setGeometry(QRect(400, 200, 200, 70));
    start->setStyleSheet("background-color: rgb(150, 1, 200); "
                         "border-radius: 10px;");
    start->show();

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
