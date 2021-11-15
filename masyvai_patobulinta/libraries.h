//
// Created by Jaune Malukaite on 2021-10-24.
//

#ifndef V_01_REALIZACIJA_SU_MASYVAIS_LIBRARIES_H
#define V_01_REALIZACIJA_SU_MASYVAIS_LIBRARIES_H
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <random>

struct Studentas {
    std::string vardas, pavarde;
    int ndSkaicius = 0;
    int *namuDarbai = new int[ndSkaicius];
    double namuDarbuSuma = 0;
    int egzaminas;
    double galutinis;
};

#endif //V_01_REALIZACIJA_SU_MASYVAIS_LIBRARIES_H
