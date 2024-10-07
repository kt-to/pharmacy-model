//
// Created by Дмитрий Фоминых on 07.10.2024.
//
//#pragma once
#include "person.h"
#include "medicament.h"
#include "random"

std::mt19937 r2d2(time(nullptr));

person::person() {
    _gender = (r2d2() % 2 == 1);
    if (_gender) {
        _name = gen_man();
    } else {
        _name = gen_women();
    }
    _surname = gen_surname();
    _age = 16 + (r2d2() % 74);
    _free_time = r2d2() % 3600;
    _coins = r2d2() % 10'000;
    _med_card = {};
    _therapy = {};
}

void person::print() {
    std::cout << "-------------------\n";
    std::cout << "   name  " << _name << "\n";
    std::cout << "surname  " << _surname << "\n";
    std::cout << "    age  " << _age << "\n";
    std::cout << "-------------------\n";
}