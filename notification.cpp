//
// Created by Владислав Отвагин on 08.10.2024. но Владислав Отвагин только создал...
//

#include "notification.h"
#include <random>
#include <QTextEdit>
#include "person.h"
#include "medicament.h"

notification::notification(person *order, QWidget *parent ) {
    from = order;
    waiting_list = {};
    this->parent = parent;
}

notification::notification(notification &other, QWidget *parent ) {
    this->from = other.from;
    this->waiting_list = other.waiting_list;
    this->next = other.next;
    this->parent = parent;

}

void notification::add_medicament_in_list(medicament &now) {
    waiting_list.push_back(now);

}

bool notification::empty() {
    return waiting_list.size() == 0ull;
}

void notification::make_beautiful() {
    label->setStyleSheet("background-color: rgba(0, 0, 0, 70); border-radius: 20px;");
    QTextEdit *name = new QTextEdit(label);
    name->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    name->setGeometry(400/(from->get_name() + ' ' + this->from->get_surnam()).size(), 20, (from->get_name() + ' ' + this->from->get_surnam()).size()*15, 25);
    name->setText(QString::fromStdString(from->get_name() + ' ' + this->from->get_surnam()) +' '+ QString::number(from->get_age()) + " y.o.");
    name->show();


}

void notification::paint(int curry) {
        label = new QLabel(parent);
        label->setGeometry(800, curry, 200, 100);
        label->setStyleSheet("background-color: rgb(255, 255, 255);");
        label->show();
        make_beautiful();

}



notification::notification() {

}

