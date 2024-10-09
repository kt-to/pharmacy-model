//
// Created by Владислав Отвагин on 08.10.2024. а писал в файле Дима ночью
//

#pragma once
#include "back.h"
#include "person.h"
#include <QLabel>
#include <QPushButton>
class notification {
public:
    notification(person * order);
    notification();
    notification(notification & other);
    void add_medicament_in_list(medicament& now);
    bool empty();
    void make_beautiful();
    void call(notification* root, QWidget * parent);
    void add(notification* &root, notification * &n);
    void del(int ind,  notification *&root);
    void paint(notification* root, QWidget * parent);
private:
    QLabel * label;
    QPushButton * close;
    notification * next = 0;
    person* from;
    std::vector<medicament> waiting_list;
};

