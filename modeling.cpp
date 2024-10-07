//
// Created by Владислав Отвагин on 06.10.2024.
//

#include "modeling.h"
#include "Animation.h"
#include <QTimer>
#include <QGraphicsView>

modeling::modeling(QString s) {
    file = s;
    this->setFixedHeight(900);
    this->setFixedWidth(1100);
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
        if(horisontal_roads[i] >= b) {
            last_horisontal_road = i;
            break;
        }
    }
    for(int i = 0 ; i < 4; ++i) {
        if(vertical_roads[i] >= a) {
            last_vertucal_road = i;
            break;
        }
    }
    b = horisontal_roads[last_horisontal_road] ;
    // b = vertical_roads[last_vertucal_road] - 10;
    int curr_h;
    int curr_v;
    curr_v = beg->x();
    curr_h = beg->y();
    std::vector <QPoint> points;
    points.push_back(QPoint(curr_v, curr_h));
    b = horisontal_roads[last_horisontal_road] + 10;
    // while(curr_h >= b) {
    //    last_horisontal_road--;
    //     curr_h = horisontal_roads[last_horisontal_road];
    //     if(curr_h >= b) break;
        points.push_back(QPoint(curr_v, horisontal_roads[last_horisontal_road]));
    // }
    points.push_back(QPoint(a, horisontal_roads[last_horisontal_road]));
    points.push_back(QPoint(a, b));
    deliver_queue.push(points);
}

void modeling::send_order() {
    int a = QInputDialog::getInt(this, "int", "int");
    int b = QInputDialog::getInt(this, "int", "int");
    new_order(a, b);
}

void modeling::deliver_order() {
    if(!deliver_queue.empty() && (!delliveler1 || !delliveler2 || !delliveler3)) {
        std::vector <QPoint> points = deliver_queue.front();
        deliver_queue.pop();
        std::vector <QGraphicsItem*> item;
        for(int i = 1; i < points.size(); ++i) {
            QGraphicsLineItem * line = new QGraphicsLineItem();
            line->setPen(QPen(Qt::red));
            line->setLine(QLine(points[i-1], points[i]));
            item.push_back(line);
            scene->addItem(line);
        }
        if(!delliveler1) {
            delliveler1 = new QLabel();
            delliveler1->setGeometry(QRect(beg->x(), beg->y(), 7, 7));
            delliveler1->setFixedSize(7, 7);
            delliveler1->setStyleSheet("background-color: rgb(40, 0, 200); border-radius: 3px;");
            scene->addWidget(delliveler1);
            Animation *a = new Animation(points, delliveler1);

            a->moveToThread(frst);
            a->startAnimation(delliveler1);

            delete delliveler1;
            delliveler1 = 0;

        } else if(!delliveler2) {
            delliveler2 = new QLabel();
            delliveler2->setGeometry(QRect(beg->x(), beg->y(), 7, 7));
            delliveler2->setFixedSize(7, 7);
            delliveler2->setStyleSheet("background-color: rgb(40, 0, 200); border-radius: 2px;");
            delliveler2->show();
            scene->addWidget(delliveler2);
            Animation *a = new Animation(points);
            a->moveToThread(frst);
            a->startAnimation(delliveler2);
            delete delliveler2;
            delliveler2 = 0;
        } else {
            delliveler3 = new QLabel();
            delliveler3->setGeometry(QRect(beg->x(), beg->y(), 7, 7));
            delliveler3->setFixedSize(7, 7);
            delliveler3->setStyleSheet("background-color: rgb(40, 0, 200); border-radius: 3px;");
            delliveler3->show();
            scene->addWidget(delliveler3);
            Animation *a = new Animation(points);
            a->moveToThread(frst);
            a->startAnimation(delliveler3);
            delete delliveler3;
            delliveler1  = 0;
        }
        deliver_timer->start();
        for(int i= 0; i < item.size(); ++i) {
            delete item[i];
        }
    }
}