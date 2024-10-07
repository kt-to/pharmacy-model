//
// Created by Дмитрий Фоминых on 07.10.2024.
//
#pragma once
#include "back.h"
#include "vector"
#include "random"

std::string gen_man() {
    std::vector<std::string> all {
        "Adelbert", "Alois", "Bernhard",
        "Christoph", "Dieter", "Gustl",
        "Hanno", "Gotz", "Eric", "Henri",
        "Jan", "Johann", "Konrad",
        "Willi", "Wenzel", "Adolf",
        "Vlaaaaad"
    };
    std::mt19937 rd;
    return all[rd() % all.size()];
}

std::string gen_women() {
    std::vector<std::string> all {
            "Anne", "Annika", "Berta",
            "Bianka", "Carry", "Elke",
            "Eva", "Friedl", "Grit", "Helga",
            "Hilda", "Irmgard", "Johanna",
            "Kerstin", "Wenzel", "Adolf",
            "Tanja"
    };
    std::mt19937 rd;
    return all[rd() % all.size()];
}

std::string gen_surname() {
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
    std::mt19937 rd;
    return all[rd() % all.size()];
}

