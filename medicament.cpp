//
// Created by Дмитрий Фоминых on 07.10.2024.
//
#include "medicament.h"
#include "random"
#include "ill.cpp"
#include "back.h"
#include "iostream"
#include "algorithm"

std::mt19937 rg;

medicament::medicament() {
    _level = rg() % 10;
    int a = _level * 100 + rg() % 51 - 26;
    _cost = std::max(a, 10);
    _name = gen_name_medicament();
    _indications = gen_ill();
    _reference = gen_ref(*this);
}

std::string medicament::get_name() {
    return _name;
}

std::string medicament::get_indications() {
    return _indications;
}

std::string medicament::get_ref() {
    return _reference;
}

int medicament::get_level() {
    return _level;
}

void medicament::print() {
    std::cout << _name << "\n"
    << _indications << "\n" <<
    "Level: " << _level << "\n" <<
    _cost << "$ \n" << _reference << "\n\n";
}