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

    std::string get_name();
    std::string get_surnam();
    std::string get_age();
    std::vector<medicament> get_therapy();
    std::pair<int, int> get_address();


protected:
    std::pair<int, int> _address;
    int _age;
    size_t _free_time;
    long long _coins;
    bool _gender;
    std::string _name;
    std::string _surname;
    std::vector<std::vector<ill>> _med_card;
    std::vector<medicament> _therapy;
};
