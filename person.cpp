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
    _free_time_hour = gen_hour();
    _free_time_minute = gen_minute();
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
    std::cout << "    time when coll   " << _free_time_hour
    << ":" << _free_time_minute << "\n";
    std::cout << "    coins            " << _coins << "\n";
    std::cout << "---------------------------------------\n";
}

std::pair<int, int> person::get_address() {
    return _address;
}

std::string person::get_age() {
    int now = _age;
    std::string ans;
    while (now > 0) {
        ans.push_back(now % 10 + '0');
        now /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

std::string person::get_name() {
    return _name;
}

std::string person::get_surnam() {
    return _surname;
}

std::vector<medicament> person::get_therapy() {
    return _therapy;
}