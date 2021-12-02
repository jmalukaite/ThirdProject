//
// Created by Jaune Malukaite on 2021-12-02.
//

#ifndef INC_1_1VERSIJA_FUNKCIJOSSTRUCT_H
#define INC_1_1VERSIJA_FUNKCIJOSSTRUCT_H
double NamuDarbuVidurkioSkaiciavimas(StudentasStruct studentas);

void NuskaitymasIsFailo(vector<StudentasStruct> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void SkirstymasIGrupes(vector<StudentasStruct> &studentai,
                       vector<StudentasStruct> &aukstesniojoLygio, vector<StudentasStruct> &zemesniojoLygio);

void Spausdinimas(int studentuSkaicius, const vector<StudentasStruct> &aukstesniojoLygio,
                  const vector<StudentasStruct> &zemesniojoLygio);
#endif //INC_1_1VERSIJA_FUNKCIJOSSTRUCT_H
