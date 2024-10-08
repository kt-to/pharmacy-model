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
        "Adelbert", "Alois", "Bernhard",
        "Christoph", "Dieter", "Gustl",
        "Hanno", "Gotz", "Eric", "Henri",
        "Jan", "Johann", "Konrad",
        "Willi", "Wenzel", "Adolf",
        "Vlaaaaad"
    };

    return all[rd() % all.size()];
}

std::string gen_women() {
    srand(time(0));
    std::vector<std::string> all {
            "Anne", "Annika", "Berta",
            "Bianka", "Carry", "Elke",
            "Eva", "Friedl", "Grit", "Helga",
            "Hilda", "Irmgard", "Johanna",
            "Kerstin", "Wenzel", "Adolf",
            "Tanja"
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
            "Bru", "Dro", "Arz", "Lo",
            "Gool", "Re", "Jo", "Popfhi",
            "Eloo", "Xoi", "Asor", "Ghoi",
            "II", "Uoi", "Worm"
    };
    std::vector<std::string> suf {
            "in", "ill", "ir",
            "dil", "zil", "cil",
            "fil", "moil", "ril",
            "sill", "phil", "toil",
            "eii", "sop", "dop"
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
