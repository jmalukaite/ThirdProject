#ifndef VERSIJA_05_REALIZACIJA_SU_LIST_H
#define VERSIJA_05_REALIZACIJA_SU_LIST_H
double NamuDarbuVidurkioSkaiciavimasLIST(Studentas studentas);

void NuskaitymasIsFailoLIST(list<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void SkirstymasIGrupesLIST(list<Studentas> &studentai, list<Studentas> &aukstesniojoLygio,
                       list<Studentas> &zemesniojoLygio);

void SpausdinimasLIST(int studentuSkaicius, list<Studentas> &aukstesniojoLygio,
                  list<Studentas> &zemesniojoLygio);
#endif //VERSIJA_05_REALIZACIJA_SU_LIST_H
