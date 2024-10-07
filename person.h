//
// Created by Дмитрий Фоминых on 07.10.2024.
//

#include "string"
#include "iostream"
#include "vector"
#include "back.h"

class person {
public:
    person();
    void print();
private:
    int _age;
    bool _gender;
    std::string _name;
    std::string _surname;
    std::vector<std::vector<ill>> _med_card;
    std::vector<medicament> _therapy;
};
