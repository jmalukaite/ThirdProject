#include "libraries.h"
#include "1strategija_list.h"

double LISTNamuDarbuVidurkioSkaiciavimas(Studentas studentas) {
    double vidurkis =
            accumulate(studentas.namuDarbai.begin(), studentas.namuDarbai.end(), 0.0) / studentas.namuDarbai.size();
    return vidurkis;
}

void LISTAtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius) {
    string pavadinimas = "StudentaiLIST" + to_string(studentuSkaicius) + ".txt";
    ofstream stud(pavadinimas);
    srand(time(NULL));

    for (int i = 0; i < studentuSkaicius; i++) {
        stud << "Vardas" + to_string(i + 1) << " " << "Pavarde" + to_string(i + 1) << " ";
        for (int j = 0; j < namuDarbuSkaicius + 1; j++) { //+1 nes prisideda egzamino pazymys
            stud << rand() % 10 + 1 << " ";
        }
        stud << endl;
    }
}

void LISTNuskaitymasIsFailo(list<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "StudentaiLIST" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);

    while (indeksas < studentuSkaicius) {
        Studentas studentas;
        fd >> studentas.vardas;
        fd >> studentas.pavarde;
        int ivestis;
        for (int i = 0; i < namuDarbuSkaicius; i++) {
            fd >> ivestis;
            studentas.namuDarbai.push_back(ivestis);
        }
        fd >> studentas.egzaminas;
        studentas.galutinis = LISTNamuDarbuVidurkioSkaiciavimas(studentas) * 0.4
                              + studentas.egzaminas * 0.6;
        studentai.push_back(studentas);
        indeksas++;
    }
}

void LISTSkirstymasIGrupes(list<Studentas> studentai, list<Studentas> &aukstesniojoLygio,
                           list<Studentas> &zemesniojoLygio, int &zemesnioL, int &aukstesnioL) {

    list<Studentas>::iterator it;

    for (it = studentai.begin(); it != studentai.end(); ++it) {
        if (it->galutinis < 5.00) {
            Studentas zemesnis;
            zemesnis.vardas = it->vardas;
            zemesnis.pavarde = it->pavarde;
            zemesnis.galutinis = it->galutinis;
            zemesniojoLygio.push_back(zemesnis);
            zemesnioL++;
        } else {
            Studentas aukstesnis;
            aukstesnis.vardas = it->vardas;
            aukstesnis.pavarde = it->pavarde;
            aukstesnis.galutinis = it->galutinis;
            aukstesniojoLygio.push_back(aukstesnis);
            aukstesnioL++;
        }
    }
}

void LISTSpausdinimas(int studentuSkaicius, list<Studentas> &aukstesniojoLygio,
                      list<Studentas> &zemesniojoLygio, int zemesnioL, int aukstesnioL) {
    string zemesniujuPavadinimas = "ŽemesniojoLygioStudentaiLIST" + to_string(studentuSkaicius) + ".txt";
    ofstream zem(zemesniujuPavadinimas);
    string aukstesniujuPavadinimas = "AukštesniojoLygioStudentaiLIST" + to_string(studentuSkaicius) + ".txt";
    ofstream aukst(aukstesniujuPavadinimas);

    for (Studentas zemesnis : zemesniojoLygio) {
        zem << zemesnis.vardas << " " <<
            zemesnis.pavarde << " " << fixed << setprecision(2) <<
            zemesnis.galutinis << endl;
    }
    for (Studentas aukstesnis : aukstesniojoLygio) {
        aukst << aukstesnis.vardas << " " <<
              aukstesnis.pavarde << " " << fixed << setprecision(2) <<
              aukstesnis.galutinis << endl;
    }
    zemesniojoLygio.clear();
    aukstesniojoLygio.clear();
}