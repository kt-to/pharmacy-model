//
// Created by Дмитрий Фоминых on 07.10.2024.
//
#include "back.h"
#include "string"
#include "vector"

class medicament {
public:
    medicament();

    void print();

    std::string get_ref();
private:
    std::string _name;
    std::string _reference;
    std::vector<ill> _indications;
    int level;
};

