//
// Created by Jaune Malukaite on 2021-12-15.
//

#ifndef INC_2_0VERSIJA_FUNKCIJOS_H
#define INC_2_0VERSIJA_FUNKCIJOS_H
void NuskaitymasKLASE(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void SkirstymasIGrupesKLASE(vector<Studentas> &studentai,
                            vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio);

void SpausdinimasKLASE(int studentuSkaicius, const vector<Studentas> &aukstesniojoLygio,
                       const vector<Studentas> &zemesniojoLygio);
#endif //INC_2_0VERSIJA_FUNKCIJOS_H
