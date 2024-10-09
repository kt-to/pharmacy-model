//
// Created by Владислав Отвагин on 06.10.2024.
//

#include "modeling.h"
#include "Animation.h"
#include <QTimer>
#include <QGraphicsView>
#include "notification.h"

modeling::modeling(QString s) {
    file = s;
    this->setFixedHeight(700);
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

    deliver_timer1 = new QTimer(this);
    deliver_timer1->setInterval(1000);
    deliver_timer1->start();
    deliver_timer2 = new QTimer(this);
    deliver_timer2->setInterval(1250);
    deliver_timer2->start();
    deliver_timer3 = new QTimer(this);
    deliver_timer3->setInterval(1500);
    deliver_timer3->start();
    view = new QGraphicsView(this);
    scene = new QGraphicsScene();
    view->setScene(scene);
    view->setGeometry(QRect(50, 70, 1000, 600));
    scene->setSceneRect(0,0, 1300, 1000);
    back = new QLabel();
    back->setGeometry(QRect(0, 0, 1300, 1000));
    QPixmap pixmap = QPixmap(file + "/images/map.jpg");
    back->setPixmap(pixmap);
    scene->addWidget(back);
    frst = new QThread();
    scnd = new QThread();
    thrd = new QThread();

    time = new QTimer();
    time->setInterval(2000/60);
    time->start();
    min = 0;
    hour = 8;
    order = new QPushButton(this);
    order->setGeometry(QRect(10, 10, 75, 25));
    order->setText("Order");
    check_timer = new QTimer(this);
    check_timer->setInterval(100);

    curr_time = new QLabel(this);
    curr_time->setGeometry(QRect(150, 10, 75, 25));
    curr_time->setText("8:00");


    notification* root = new notification;
    notification* notif = new notification;
    notif->add(root, notif);
    notif->call(root, this);
    connect(time, &QTimer::timeout, this, &modeling::update_time);
    connect(order, &QPushButton::clicked, this, &modeling::send_order);
    connect(deliver_timer1, &QTimer::timeout, this, &modeling::deliver_order);
    connect(deliver_timer2, &QTimer::timeout, this, &modeling::deliver_order);
    connect(deliver_timer3, &QTimer::timeout, this, &modeling::deliver_order);
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
    month = 8;
    day = 1;
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
    points.push_back(QPoint(a, horisontal_roads[last_horisontal_road]));
    points.push_back(QPoint(curr_v, horisontal_roads[last_horisontal_road]));
    points.push_back(QPoint(curr_v, curr_h));

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
            line->setLine(QLine(points[i-1] + QPoint(3, 3), points[i]+ QPoint(3, 3)));
            item.push_back(line);
            scene->addItem(line);
        }
        if(!delliveler1) {
            delliveler1 = new QLabel();
            delliveler1->setGeometry(QRect(beg->x(), beg->y(), 7, 7));
            delliveler1->setFixedSize(7, 7);
            delliveler1->setStyleSheet("background-color: rgb(40, 0, 200); border-radius: 3px;");
            scene->addWidget(delliveler1);
             animation1 = new Animation(points, delliveler1);
            // a->moveToThread(frst);
            items1 = item;
            animation1->startAnimation(delliveler1, item);
            connect(animation1, &Animation::animationFinished, this, &modeling::stop_1);
            // frst->start();
            //delete delliveler1;
            // delliveler1 = 0;
        } else if(!delliveler2) {

            delliveler2 = new QLabel();
            delliveler2->setGeometry(QRect(beg->x(), beg->y(), 7, 7));
            delliveler2->setFixedSize(7, 7);
            delliveler2->setStyleSheet("background-color: rgb(40, 0, 200); border-radius: 3px;");
            delliveler2->show();
            scene->addWidget(delliveler2);
            animation2 = new Animation(points);
            // a->moveToThread(scnd);
            items2 = item;
            animation2->startAnimation(delliveler2, item);
            connect(animation2, &Animation::animationFinished, this, &modeling::stop_2);
            // scnd->start();
            //delete delliveler2;
            // delliveler2 = 0;
        } else {
            delliveler3 = new QLabel();
            delliveler3->setGeometry(QRect(beg->x(), beg->y(), 7, 7));
            delliveler3->setFixedSize(7, 7);
            delliveler3->setStyleSheet("background-color: rgb(40, 0, 200); border-radius: 3px;");
            delliveler3->show();
            scene->addWidget(delliveler3);
            animation3 = new Animation(points);
            // a->moveToThread(thrd);
            items3 = item;
            animation3->startAnimation(delliveler3, item);
            // thrd->start();
            connect(animation3, &Animation::animationFinished, this, &modeling::stop_3);

            // delete delliveler3;
            // delliveler3 = 0;
        }
    }
}

void modeling::stop_1() {
    if(delliveler1) {
        delete delliveler1;
        delliveler1 = NULL;
        for(int i = 0; i < items1.size(); ++i) {
            delete items1[i];
        }
    }
}
void modeling::stop_2() {
    if(delliveler2) {
        delete delliveler2;
        delliveler2 = NULL;
        for(int i = 0; i < items2.size(); ++i) {
            delete items2[i];
        }
    }
}
//ура
void modeling::stop_3() {
    if(delliveler3) {
        delete delliveler3;
        delliveler3 = NULL;
        for(int i = 0;i < items3.size(); ++i) {
            delete items3[i];
        }
    }
}

void modeling::update_time() {
    if(min == 59) {
        hour++;
        min = 0;
    } else {
        min++;
    }
    if(hour == 23) {
        day++;
        hour = 8;
        if(day==31) {
            month++;
            day = 1;
        }
    }
    curr_time->setText( ( (month < 10) ? QString::number(0): "")  + QString::number(month) +  '-'+( (day < 10) ? QString::number(0): "")+QString::number(day) +' ' + QString::number(hour) + ':' +  ( (min < 10) ? QString::number(0): "") + QString::number(min));

}
