//
// Created by Дмитрий Фоминых on 07.10.2024.
//
#pragma once
#include "back.h"
#include "string"
#include "vector"

class medicament {
public:
    medicament();

    void print();

    void set_ref(std::string text);
    void set_name(std::string name);

    std::string get_ref();
private:
    std::string _name;
    std::string _reference;
    ill _indications;
    int level;
};

