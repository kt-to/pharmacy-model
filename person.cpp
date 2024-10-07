//
// Created by Дмитрий Фоминых on 07.10.2024.
//
//#pragma once
#include "person.h"
#include "medicament.h"
#include "random"

person::person() {
    _gender = (rand() % 2 == 1);
    if (_gender) {
        _name = gen_man();
    } else {
        _name = gen_women();
    }
    _surname = gen_surname();
    _age = 16 + (rand() % 74);
    _med_card = {};
    _therapy = {};
}

void person::print() {
    std::cout << "   name  " << _name << "\n";
    std::cout << "surname  " << _surname << "\n";
    std::cout << "    age  " << _age << "\n";
    std::cout << "-------------------------------\n";
}