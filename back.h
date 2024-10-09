//
// Created by Дмитрий Фоминых on 07.10.2024.
//
#pragma once
#include "string"

enum class ill;
class medicament;
class person;
class notification;

// service functions
void end_day(std::vector<medicament>& base, int coins, std::vector<medicament>& all_med, int day_number);
void end_day(std::vector<person>& base, std::vector<person>& dad_list);

// generatos
std::string gen_man();
std::string gen_women();
std::string gen_surname();
std::string gen_name_medicament();
std::string gen_ill();
std::string gen_ref(medicament& object);
int gen_minute();
int gen_hour();