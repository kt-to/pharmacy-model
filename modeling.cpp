//
// Created by Владислав Отвагин on 06.10.2024.
//

#include "modeling.h"
#include "Animation.h"
#include <QTimer>
#include <QGraphicsView>

modeling::modeling(QString s) {
    file = s;
    this->setFixedHeight(1100);
    this->setFixedWidth(1300);
    horisontal_roads.resize(7);
    horisontal_roads[0] = 5;
    horisontal_roads[1] = 190;
    horisontal_roads[2] = 285;
    horisontal_roads[3] = 380;
    horisontal_roads[4] = 566;
    horisontal_roads[5] = 758;
    horisontal_roads[6] = 942;
    vertical_roads.resize(4);
    vertical_roads[0] = 150;
    vertical_roads[1] = 445;
    vertical_roads[2] = 731;
    vertical_roads[3] = 1050;
    frst = new QThread();
    scnd = new QThread();
    thrd = new QThread();
    deliver_timer = new QTimer(this);
    deliver_timer->setInterval(1000);
    deliver_timer->start();
    view = new QGraphicsView(this);
    scene = new QGraphicsScene();
    view->setScene(scene);
    view->setGeometry(QRect(50, 100, 1000, 600));
    scene->setSceneRect(0,0, 1300, 1000);
    back = new QLabel();
    back->setGeometry(QRect(0, 0, 1300, 1000));
    QPixmap pixmap = QPixmap(file + "/images/map.jpg");
    back->setPixmap(pixmap);
    scene->addWidget(back);

    order = new QPushButton(this);
    order->setGeometry(QRect(10, 10, 75, 25));
    order->setText("Order");
    connect(order, &QPushButton::clicked, this, &modeling::send_order);
    connect(deliver_timer, &QTimer::timeout, this, &modeling::deliver_order);
}



void modeling::new_order(int a, int b) {
    int last_horisontal_road = 6;
    int last_vertucal_road = 3;
    for(int i = 0 ; i < 7; ++i) {
        if(horisontal_roads[i] >= a) {
            last_horisontal_road = i;
            break;
        }
    }
    for(int i = 0 ; i < 4; ++i) {
        if(vertical_roads[i] >= b) {
            last_vertucal_road = i;
            break;
        }
    }
    b = vertical_roads[last_vertucal_road ] ;
    // b = vertical_roads[last_vertucal_road] - 10;
    int curr_h;
    int curr_v;
    curr_h = beg->x();
    curr_v = beg->y();
    std::vector <QPoint> points;
    points.push_back(QPoint(curr_h, curr_v));

    while(curr_v > b) {
        last_horisontal_road = last_horisontal_road - 1;
        curr_v = horisontal_roads[last_horisontal_road] ;
        if(curr_v > b) break;
        points.push_back(QPoint(curr_h, curr_v));
    }
    points.push_back(QPoint(a, b));
    deliver_queue.push(points);
}

void modeling::deliver_order() {
    if(!deliver_queue.empty() && (!delliveler1 || !delliveler2 || !delliveler3)) {
        std::vector <QPoint> points = deliver_queue.front();
        deliver_queue.pop();
        if(!delliveler1) {
            delliveler1 = new QLabel();
            delliveler1->setGeometry(QRect(beg->x(), beg->y(), 8, 8));
            delliveler1->setStyleSheet("background-color: rgb(40, 0, 200); border-radius: 4px;");
            scene->addWidget(delliveler1);

            Animation *a = new Animation(points);
            a->moveToThread(frst);
            a->startAnimation(delliveler1);

        } else if(!delliveler2) {
            delliveler2 = new QLabel();
            delliveler2->setGeometry(QRect(beg->x(), beg->y(), 100, 100));
            delliveler2->setStyleSheet("background-color: rgb(40, 0, 200); border-radius: 2px;");
            delliveler2->show();
            scene->addWidget(delliveler2);
            Animation *a = new Animation(points);
            a->moveToThread(frst);
            a->startAnimation(delliveler2);
        } else {
            delliveler3 = new QLabel();
            delliveler3->setGeometry(QRect(beg->x(), beg->y(), 100, 100));
            delliveler3->setStyleSheet("background-color: rgb(40, 0, 200); border-radius: 2px;");
            delliveler3->show();
            scene->addWidget(delliveler3);
            Animation *a = new Animation(points);
            a->moveToThread(frst);
            a->startAnimation(delliveler3);
        }
    }
}

void modeling::send_order() {
    int a = 200, b = 200;
    new_order(a, b);
}