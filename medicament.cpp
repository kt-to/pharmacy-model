//
// Created by Дмитрий Фоминых on 07.10.2024.
//
#include "medicament.h"
#include "random"
#include ""

std::mt19937 rg;

medicament::medicament() {
    level = rg() % 10;
    _name = "Ha";
    _reference = "ref";
    _indications = rg % ;
}