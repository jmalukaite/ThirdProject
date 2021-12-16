#include "studentas.h"
#include "funkcijos.h"

int main() {

    int namuDarbuSkaicius = 4;
    string pavadinimas;
    /** initializing how many students and files will there be */
    int studentuSkaiciai[1] = {100000};

    vector<Studentas> studentai;
    vector<Studentas> aukstesniojoLygio;
    vector<Studentas> zemesniojoLygio;

    for (int i : studentuSkaiciai) {
        /** functions are used for the files that have been given separately */
        int studentuSkaicius = i;
        NuskaitymasKLASE(studentai, studentuSkaicius, namuDarbuSkaicius);
        SkirstymasIGrupesKLASE(studentai, aukstesniojoLygio, zemesniojoLygio);
        SpausdinimasKLASE(studentuSkaicius, aukstesniojoLygio, zemesniojoLygio);
        studentai.clear();
        aukstesniojoLygio.clear();
        zemesniojoLygio.clear();
    }
}