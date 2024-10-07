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
class modeling : public QMainWindow {
public:
    modeling(QString s);
    void new_order(int a, int b);
    void deliver_order();
    void send_order();
private:
    QPushButton *order;
    QString file;
    QPoint *beg = new QPoint(1050, 940);
    std::vector <int> horisontal_roads;
    std::vector <int> vertical_roads;
    QLabel *delliveler1 = 0, *delliveler2 = 0, *delliveler3 = 0;
    QThread *frst, *scnd, *thrd;
    std::queue < std::vector <QPoint>> deliver_queue;
    QTimer *deliver_timer;
    QLabel* back;
    QGraphicsScene *scene;
    QGraphicsView *view;
};



#endif //MODELING_H
