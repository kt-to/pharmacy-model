//
// Created by Дмитрий Фоминых on 07.10.2024.
//
#include "medicament.h"
#include "random"
#include "ill.cpp"
#include "back.h"
#include "iostream"

std::mt19937 rg;

medicament::medicament() {
    level = rg() % 10;
    _name = gen_name_medicament();
    _reference = "ref";
    _indications = ill(rg() % 12);

}

void medicament::print() {
    std::cout << _name << "\n";
}