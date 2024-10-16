//
// Created by Владислав Отвагин on 08.10.2024. а писал в файле Дима ночью
//

#pragma once
#include "person.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QtCore>

class notification : public QWidget{
public:
    explicit notification(person * order, QWidget *parent = nullptr);
    explicit notification();
    explicit notification(notification & other, QWidget *parent = nullptr);
    notification*& get_next() {
        return next;
    }
    void set_next(notification * next) {
        this->next = next;
    }
    void add_medicament_in_list(medicament& now);
    bool empty();
    void make_beautiful();
    void call(notification* root, QWidget * parent);
    void add(notification* &root, notification * &n);
    void del(int ind,  notification *&root);
    void paint(int y);
    bool operator!=(const notification &other) {
        if(other.from != from)
            return 1;
        return 0;
    }
    void clear() {
        delete label;
    }
    friend class notification_list;
    // void operator=(notification& other) {
    //     from = other.from;
    //     waiting_list = other.waiting_list;
    //     next = other.next;
    //     close = other.close;
    //     label = other.label;
    // }
private:
    notification*next = 0;
    QLabel * label = 0;
    QPushButton * close = 0;
    person* from = 0;
    QWidget * parent;
    std::vector<medicament> waiting_list = {};
};

