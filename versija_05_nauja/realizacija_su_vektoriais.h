#ifndef VERSIJA_05_REALIZACIJA_SU_VEKTORIAIS_H
#define VERSIJA_05_REALIZACIJA_SU_VEKTORIAIS_H
double NamuDarbuVidurkioSkaiciavimasVECTOR(Studentas studentas);

void NuskaitymasIsFailoVECTOR(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void SkirstymasIGrupesVECTOR(vector<Studentas> &studentai,
                       vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio);

void SpausdinimasVECTOR(int studentuSkaicius, const vector<Studentas> &aukstesniojoLygio,
                  const vector<Studentas> &zemesniojoLygio);
#endif //VERSIJA_05_REALIZACIJA_SU_VEKTORIAIS_H
