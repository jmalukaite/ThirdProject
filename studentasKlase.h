//
// Created by Jaune Malukaite on 2021-12-01.
//

#ifndef INC_1_1VERSIJA_STUDENTASKLASE_H
#define INC_1_1VERSIJA_STUDENTASKLASE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>
#include <chrono>
using namespace std;

class Studentas {
private:
    string vardas, pavarde;
    vector<int> namuDarbai;
    int egzaminas;
public:
    Studentas() : egzaminas(0) {};
    Studentas(ifstream& fd, int namuDarbuSkaicius);
    inline string getVardas() const { return vardas;}
    inline string getPavarde() const { return pavarde;}
    double getGalutinis();
    void readStudentas(ifstream&, int);

};

#endif //INC_1_1VERSIJA_STUDENTASKLASE_H
