//
// Created by Jaune Malukaite on 2021-11-16.
//

#ifndef INC_1_0_VERSIJA_1STRATEGIJA_2STRATEGIJA_VECTOR_H
#define INC_1_0_VERSIJA_1STRATEGIJA_2STRATEGIJA_VECTOR_H
double VECTOR2NamuDarbuVidurkioSkaiciavimas(Studentas studentas);

void VECTOR2AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius);

void VECTOR2NuskaitymasIsFailo(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void VECTOR2SkirstymasIGrupes(vector<Studentas> &studentai, vector<Studentas> &zemesniojoLygio);

bool Palyginimas(Studentas studentas);

void VECTOR2Spausdinimas(int studentuSkaicius, const vector<Studentas> &studentai,
                        const vector<Studentas> &zemesniojoLygio);
#endif //INC_1_0_VERSIJA_1STRATEGIJA_2STRATEGIJA_VECTOR_H
