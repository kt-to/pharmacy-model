
#ifndef NOTIFICATION_LIST_H
#define NOTIFICATION_LIST_H

#include "notification.h"


class notification_list {
public:
   explicit notification_list() = default;
    ~notification_list();
    void set_widget(QWidget *widget) {
        this->widget = widget;
    }
    void add_notification(notification *any) {
        any->set_next(root);

        this->root = any;
        least.push_back(any);
        show();
    }
    void show() {
        int y = 20;
        notification* curr = root;
        while(curr) {
            curr->clear();
            curr->paint(y);
            curr = curr->next;
            y+=110;
        }
    }

    void pop() {
        auto curr = root;
        while(curr->next) {
            curr = curr->next;
        }
        auto temp = curr;
        curr = nullptr;
        delete temp;
        delete least[0];
        least.erase(least.begin());
        show();
    }
     notification* get_root() {
        return root;
    }

private:
    std::vector <notification* > least;
    QWidget* widget;
    notification* root;

};



#endif //NOTIFICATION_LIST_H
