#ifndef INC_1_0_VERSIJA_1STRATEGIJA_2STRATEGIJA_LIST_H
#define INC_1_0_VERSIJA_1STRATEGIJA_2STRATEGIJA_LIST_H
double LIST2NamuDarbuVidurkioSkaiciavimas(Studentas studentas);

void LIST2AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius);

void LIST2NuskaitymasIsFailo(list<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void LIST2SkirstymasIGrupes(list<Studentas> &studentai, list<Studentas> &zemesniojoLygio, int &zemesnioL, int &aukstesnioL);

bool Palyginimas2(Studentas studentas);

void LIST2Spausdinimas(int studentuSkaicius, list<Studentas> &studentai,
                       list<Studentas> &zemesniojoLygio, int zemesnioL, int aukstesnioL);
#endif //INC_1_0_VERSIJA_1STRATEGIJA_2STRATEGIJA_LIST_H
