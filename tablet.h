//
// Created by Дмитрий Фоминых on 06.10.2024.
//
#include <string>

class tablet {
public:
    tablet();
    tablet(std::string name, int cost, int level);

    int get_quantity();
    int get_level();
    int get_cost();
    size_t get_expiration_date();

    void set_cost(int cost);
    void set_level(int level);
    void set_quantity(int quantity);
    void set_name(std::string name);
    void set_expiration_date(size_t expiration_date);

private:
    int _quantity;
    int _level;
    int _cost;
    std::string _name;
    size_t _expiration_date;
};
