//
// Created by Jaune Malukaite on 2021-11-15.
//

#ifndef INC_1_0_VERSIJA_1STRATEGIJA_1STRATEGIJA_LIST_H
#define INC_1_0_VERSIJA_1STRATEGIJA_1STRATEGIJA_LIST_H
double LISTNamuDarbuVidurkioSkaiciavimas(Studentas studentas);

void LISTAtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius);

void LISTNuskaitymasIsFailo(list<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void LISTSkirstymasIGrupes(list<Studentas> studentai, list<Studentas> &aukstesniojoLygio,
                       list<Studentas> &zemesniojoLygio, int &zemesnioL, int &aukstesnioL);

void LISTSpausdinimas(int studentuSkaicius, list<Studentas> &aukstesniojoLygio,
                  list<Studentas> &zemesniojoLygio, int zemesnioL, int aukstesnioL);
#endif //INC_1_0_VERSIJA_1STRATEGIJA_1STRATEGIJA_LIST_H
