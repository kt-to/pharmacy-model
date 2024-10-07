//
// Created by Владислав Отвагин on 06.10.2024.
//

#ifndef MODELING_H
#define MODELING_H

#include <QMainWindow>
#include <vector>
#include <queue>
#include <QTimer>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QThread>
#include "Animation.h"
#include <QTableWidget>
class modeling : public QMainWindow {
public:
    modeling(QString s);
    void new_order(int a, int b);
    void deliver_order();
    void send_order();
    void stopanim();
    void stop_1();
    void stop_2();
    void stop_3();
    void update_time();
private:
    QLabel* curr_time;
    QPushButton *order;
    QString file;
    QPoint *beg = new QPoint(1040, 920);
    std::vector <int> horisontal_roads;
    std::vector <int> vertical_roads;
    QLabel *delliveler1 = 0, *delliveler2 = 0, *delliveler3 = 0;
    QThread *frst, *scnd, *thrd;
    std::queue < std::vector <QPoint>> deliver_queue;
    QTimer *deliver_timer1;
    QTimer *deliver_timer2;
    QTimer *deliver_timer3;
    QLabel* back;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer * check_timer;
//ура
    int min, hour;
    int month = 8, day;
    QTimer* time;
    Animation *animation1;
    Animation *animation2;
    Animation *animation3;
    std::vector <QGraphicsItem*> items1;
    std::vector <QGraphicsItem*> items2;
    std::vector <QGraphicsItem*> items3;
};



#endif //MODELING_H
