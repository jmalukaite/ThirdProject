//
// Created by Jaune Malukaite on 2021-12-02.
//

#ifndef INC_1_2_FUNKCIJOS_H
#define INC_1_2_FUNKCIJOS_H
void NuskaitymasKLASE(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void SkirstymasIGrupesKLASE(vector<Studentas> &studentai,
                            vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio);

void SpausdinimasKLASE(int studentuSkaicius, const vector<Studentas> &aukstesniojoLygio,
                       const vector<Studentas> &zemesniojoLygio);
#endif //INC_1_2_FUNKCIJOS_H
