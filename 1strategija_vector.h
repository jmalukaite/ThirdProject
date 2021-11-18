//
// Created by Jaune Malukaite on 2021-11-15.
//

#ifndef INC_1_0_VERSIJA_1STRATEGIJA_1STRATEGIJA_VECTOR_H
#define INC_1_0_VERSIJA_1STRATEGIJA_1STRATEGIJA_VECTOR_H
double VECTORNamuDarbuVidurkioSkaiciavimas(Studentas studentas);

void VECTORAtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius);

void VECTORNuskaitymasIsFailo(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void VECTORSkirstymasIGrupes(vector<Studentas> &studentai,
                       vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio);

void VECTORSpausdinimas(int studentuSkaicius, const vector<Studentas> &aukstesniojoLygio,
                  const vector<Studentas> &zemesniojoLygio);
#endif //INC_1_0_VERSIJA_1STRATEGIJA_1STRATEGIJA_VECTOR_H
