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
    _address = {r2d2() % 1000, r2d2() % 1000};
    _surname = gen_surname();
    _age = 16 + (r2d2() % 74);
    _free_time = r2d2() % (24 * 60);
    _coins = r2d2() % 10'000;
    _med_card = {};
    _therapy = {};
}

void person::print() {
    std::cout << "\n\n\n\n\n\n\n\n---------------------------------------\n";
    std::cout << "    name             " << _name << "\n";
    std::cout << "    surname          " << _surname << "\n";
    std::cout << "    age              " << _age << "\n";
    std::cout << "    address          " << "x " << _address.first
    << " y " << _address.second << "\n";
    std::cout << "    time when coll   " << _free_time / 60
    << ":" << _free_time % 60 << "\n";
    std::cout << "    coins            " << _coins << "\n";
    std::cout << "---------------------------------------\n";
}