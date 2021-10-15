//
// Created by Jaune Malukaite on 2021-10-13.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <sstream>
#include <numeric>
#include <fstream>
#ifndef V_03_STUDENTAS_H
#define V_03_STUDENTAS_H

struct Studentas {
    std::string vardas, pavarde;
    int ndSkaicius = 0;
    std::vector<int> namuDarbai;
    double namuDarbuSuma = 0;
    int egzaminas;
    double galutinis;
    double galutinisMediana;
    double galutinisVidurkis;
};

#endif //V_03_STUDENTAS_H
