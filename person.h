//
// Created by Дмитрий Фоминых on 07.10.2024.
//
#pragma once
#include "string"
#include "iostream"
#include "medicament.h"
#include "vector"
// #include "back.h"
class person {
public:
    person();
    void print();

    std::string get_name();
    std::string get_surnam();
    int get_age();
    std::vector<medicament> get_therapy();
    std::pair<int, int> get_address();

    bool is_alive();
    bool it_his_time(int hour, int minute);
    notification* call(std::vector<medicament>& base);
    void day_end();

private:
    std::pair<int, int> _address;
    int _age;
    int _free_time_minute;
    int _free_time_hour;
    int _sellary;
    long long _coins;
    bool _gender;
    std::string _name;
    std::string _surname;
    std::vector<std::pair<std::string, int>> _med_card;
    std::vector<medicament> _therapy;
};
