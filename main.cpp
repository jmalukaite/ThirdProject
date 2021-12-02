#include "studentasKlase.h"
#include "funkcijosKlase.h"
#include "studentasStruct.h"
#include "funkcijosStruct.h"

int main() {

    int namuDarbuSkaicius = 4;
    string pavadinimas;
    int studentuSkaiciai[2] = {100000, 1000000};

    vector<Studentas> studentai;
    vector<Studentas> aukstesniojoLygio;
    vector<Studentas> zemesniojoLygio;

    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        NuskaitymasKLASE(studentai, studentuSkaicius, namuDarbuSkaicius);
        SkirstymasIGrupesKLASE(studentai, aukstesniojoLygio, zemesniojoLygio);
        SpausdinimasKLASE(studentuSkaicius, aukstesniojoLygio, zemesniojoLygio);
        studentai.clear();
        aukstesniojoLygio.clear();
        zemesniojoLygio.clear();
    }

    vector<StudentasStruct> studentaiStruct;
    vector<StudentasStruct> aukstesniojoLygioStruct;
    vector<StudentasStruct> zemesniojoLygioStruct;

    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        NuskaitymasIsFailo(studentaiStruct, studentuSkaicius, namuDarbuSkaicius);
        SkirstymasIGrupes(studentaiStruct, aukstesniojoLygioStruct, zemesniojoLygioStruct);
        Spausdinimas(studentuSkaicius, aukstesniojoLygioStruct, zemesniojoLygioStruct);
    }

    return 0;
}




