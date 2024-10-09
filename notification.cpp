//
// Created by Владислав Отвагин on 08.10.2024. но Владислав Отвагин только создал...
//

#include "notification.h"

#include <random>
#include <QtWidgets/qtextedit.h>

#include "person.h"
#include "medicament.h"

notification::notification(person *order) {
    from = order;
    waiting_list = {};
}

notification::notification(notification &other) {
    this->from = other.from;
    this->waiting_list = other.waiting_list;
    this->next = other.next;
}

void notification::add_medicament_in_list(medicament &now) {
    waiting_list.push_back(now);
}

bool notification::empty() {
    return waiting_list.size() == 0ull;
}

void notification::add(notification* &root, notification* &n) {
    n->next = root;
    root = n;
}

void notification::del(int ind, notification *&root) {
    int curr = 0;
    notification* curr_n = root;
    while(curr != ind-1) {
        ++curr;
        if(curr_n->next == 0) {
            break;
        }
        curr_n = curr_n->next;
    }
    if(curr_n->next == 0) {
        delete curr_n;
        curr_n = 0;
    }else {
        notification* temp = curr_n;
        curr_n->next = curr_n->next->next;
        delete temp;
    }
}

void notification::make_beautiful() {
    label->setStyleSheet("background-color: rgba(0, 0, 0, 100); border-radius: 20px;");
    QTextEdit *name = new QTextEdit(label);

    QTextEdit *surname = new QTextEdit(label);

    QTextEdit *age = new QTextEdit(label);

    QTextEdit *cost = new QTextEdit(label);



}

void notification::paint(notification *root, QWidget *parent) {
    notification* curr = root;
    int curry = 80;

    while(curr != 0) {
        curr->label = new QLabel(parent);
        curr->label->setGeometry(800, curry, 200, 100);
        curr->label->setStyleSheet("background-color: rgb(255, 255, 255);");
        curr->label->show();
        curr->make_beautiful();
        curry+=110;
        curr = curr->next;
    }
}

void notification::call(notification* root, QWidget* parent){
    notification* curr = root;
    while(curr != 0) {
        if(curr->label != 0) {
            delete curr->label;
            curr->label = 0;
        }
        curr = curr->next;
    }
    paint(root, parent);
}

notification::notification() {

}
