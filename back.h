//
// Created by Дмитрий Фоминых on 07.10.2024.
//

#include "string"

enum class ill;
class medicament;
class person;



// service functions
void end_day(std::vector<medicament>& base, int coins, std::vector<medicament>& all_med, int day_number = 0);
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