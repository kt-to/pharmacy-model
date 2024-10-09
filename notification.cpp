//
// Created by Владислав Отвагин on 08.10.2024. но Владислав Отвагин только создал...
//

#include "notification.h"
#include "person.h"
#include "medicament.h"

notification::notification(person *order) {
    from = order;
    waiting_list = {};
}

void notification::add_medicament_in_list(medicament &now) {
    waiting_list.push_back(now);
}

bool notification::empty() {
    return waiting_list.size() == 0ull;
}
