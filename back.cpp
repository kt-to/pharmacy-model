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
            "Bru", "Dro", "Arz"
    };
    std::vector<std::string> suf {
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
    return pref[rd() % pref.size()] + suf[rd() % suf.size()];
}
