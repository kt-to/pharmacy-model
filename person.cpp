//
// Created by Дмитрий Фоминых on 07.10.2024.
//
//#pragma once
#include "person.h"
#include "medicament.h"
#include "random"

person::person() {
    std::mt19937 rd;
    _gender = (rd() % 2 == 1);
    if (_gender) {
        _name = gen_man();
    } else {
        _name = gen_women();
    }
    _surname = gen_surname();
    _age = 16 + (rd() % 74);
    _med_card = {};
    _therapy = {};
}