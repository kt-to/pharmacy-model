//
// Created by Владислав Отвагин on 08.10.2024. а писал в файле Дима ночью
//

#pragma once
#include "back.h"
#include "person.h"

class notification {
public:
    notification(person * order);

    void add_medicament_in_list(medicament& now);

    bool empty();
private:
    person* from;
    std::vector<medicament> waiting_list;
};

