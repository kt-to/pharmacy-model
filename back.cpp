//
// Created by Дмитрий Фоминых on 07.10.2024.
//
#include "back.h"
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
            "Angerer", "Beckmann", "Brandner",
            "Bromberger", "Cronauer", "Dannecker",
            "Donauer", "Emberg", "Engelkes", "Felber",
            "Fulde", "Grotz", "Halpern",
            "Heckendorf", "Schwaiger", "Schlitt",
            "Saffer", "Rossbach", "Regener", "Preuss",
            "Pirner", "Neureuther", "Luft", "Laub",
            "Krumbiegel", "Keil", "Hofer", "Hildner",
            "Schwichtenberg", "Stalter", "Stibbe",
            "Teicher", "Wadewitz", "Weisiger", "Wiest",
            "Wunsch"
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
            "prevention",
            "heart",
            "asma",
            "psychological",
            "primary_care",
            "sleeping_pills",
            "antibiotics",
            "intestine",
            "antiretroviral",
            "antiviral_drugs",
    };
    return ills[rd() % ills.size()];
}
