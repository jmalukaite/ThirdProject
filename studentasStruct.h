//
// Created by Jaune Malukaite on 2021-12-02.
//

#ifndef INC_1_1VERSIJA_STUDENTASSTRUCT_H
#define INC_1_1VERSIJA_STUDENTASSTRUCT_H
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>
#include <chrono>

using namespace std;
struct StudentasStruct {
    string vardas, pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};
#endif //INC_1_1VERSIJA_STUDENTASSTRUCT_H
