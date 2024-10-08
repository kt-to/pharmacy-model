//
// Created by Дмитрий Фоминых on 07.10.2024.
//
#include "back.h"
#include "medicament.h"
#include "person.h"
#include "vector"
#include "random"

std::mt19937 rd(time(nullptr));


std::string gen_man() {
    srand(time(0));
    std::vector<std::string> all {
        "Adelbert", "Christoph", "Hanno",
        "Gotz", "Eric", "Henri",
        "Jan", "Johann", "Konrad",
        "Willi", "Wenzel", "Adolf",
        "Christer", "Olof", "Ivan",
        "Ivar", "Hans", "Folke",
        "Lukas", "Magnus", "Matias",
        "Mikael", "Otto", "Owe",
        "Philip", "Robert", "Ronald",
        "Simon", "Sten", "Staffan",
        "Teodor", "Vilhelm", "Vincent",
        "Trofim", "Victor", "Valery",
        "Vladislav", "Rostislav"
    };

    return all[rd() % all.size()];
}

std::string gen_women() {
    srand(time(0));
    std::vector<std::string> all {
            "Anne", "Eva", "Helga",
            "Hilda", "Johanna", "Alexandra",
            "Kerstin", "Christina", "Dora",
            "Melania", "Maria", "Lena",
            "Joanna", "Olga", "Polina",
            "Valeria", "Margarete", "Lina",
            "Tamara", "Vera", "Veronica",
            "Dominika", "Diana", "Sabina",
            "Janne", "Katrin", "Ulla",
            "Kazimiera", "Karolina", "Lada"
    };
    return all[rd() % all.size()];
}

std::string gen_surname() {
    srand(time(0));
    std::vector<std::string> all {
            "Müller", "Schmidt", "Schneider",
            "Fischer", "Weber", "Wagner",
            "Hoffmann", "Koch", "Klein",
            "Neumann", "Zimmermann", "Lehmann",
            "Peters", "Peters", "Sommer",
            "Horn", "Simon", "Bock",
            "Thiel", "Graf", "Johansson",
            "Hansen", "Andersen", "Pedersen",
            "Olesen", "Nyström", "Gustafsson",
            "Fridman", "Aas", "Jansson",
            "Viklund", "Norrström", "Lindholm"
    };
    return all[rd() % all.size()];
}

std::string gen_name_medicament() {
    srand(time(0));
    std::vector<std::string> pref {
            "Ali", "Poli", "Roli",
            "Cher", "Oli", "Woff",
            "Sup", "Fon", "Rix",
            "Demo", "Nai", "Cof",
            "Tea", "Qti", "North",
            "Xor", "Dela", "Koka",
            "Thinka", "Zor", "Geo",
            "Aero", "Vits", "Ridip",
            "Fisil", "Jor", "Morfol",
            "Paino", "Wormore", "Javap",
            "Isdo", "Hallo", "Rhich"
    };
    std::vector<std::string> suf {
            "in", "ill", "ir",
            "dil", "zil", "cil",
            "fil", "moil", "ril",
            "sill", "phil", "toil",
            "sop", "dop", "lop",
            "cin", "cop", "jod",
            "r", "nod", "dt"
    };
    return pref[rd() % pref.size()] + suf[rd() % suf.size()];
}

std::string gen_ill() {
    std::vector<std::string> ills {
            "heart",
            "pulmonary",
            "psychological",
            "fractures",
            "bleeding",
            "sleeping",
            "inflammation",
            "infections",
            "intestinal",
            "antibacterial",
            "oncological",
    };
    return ills[rd() % ills.size()];
}

std::string gen_ref(medicament& object) {
    std::string ans = "";
    std::vector<std::string> starts {
        "This pill helps with the disease ",
        "This ointment helps with ",
        "This suspension helps with ",
        "This injection is applied ",
        "This powder helps with "
    };
    ans += starts[rd() % starts.size()];
    int lv = object.get_level();
    if (lv < 2) {
        ans += "lungs ";
    } else {
        if (lv < 5) {
            ans += "regular ";
        } else {
            if (lv < 7) {
                ans += "average ";
            } else {
                if (lv < 9) {
                    ans += "serious ";
                } else {
                    ans += "deadly ";
                }
            }
        }
    }
    ans += object.get_indications();
    ans += " ills";
    return ans;
}

void end_day(std::vector<medicament>& base, int coins, std::vector<medicament>& all_med, int day_number = 0) {
    while (coins >= 1030) {
        auto elem = all_med[rd() % all_med.size()];
        base.push_back(elem);
        coins -= elem.get_cost();
    }
}

void end_day(std::vector<person>& base, std::vector<person>& dad_list) {
    std::vector<person> ans, ans2;
    for (auto to : base) {
        if (to.is_alive()) {
            to.day_end();
            ans.push_back(to);
        } else {
            ans2.push_back(to);
        }
    }
    base = ans;
    dad_list = ans2;
}
