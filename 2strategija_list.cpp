#include "libraries.h"
#include "2strategija_list.h"

double LIST2NamuDarbuVidurkioSkaiciavimas(Studentas studentas) {
    double vidurkis =
            accumulate(studentas.namuDarbai.begin(), studentas.namuDarbai.end(), 0.0) / studentas.namuDarbai.size();
    return vidurkis;
}

void LIST2AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius) {
    string pavadinimas = "StudentaiLIST2_" + to_string(studentuSkaicius) + ".txt";
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

void LIST2NuskaitymasIsFailo(list<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "StudentaiLIST2_" + to_string(studentuSkaicius) + ".txt";
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
        studentas.galutinis = LIST2NamuDarbuVidurkioSkaiciavimas(studentas) * 0.4
                              + studentas.egzaminas * 0.6;
        studentai.push_back(studentas);
        indeksas++;
    }
}

void
LIST2SkirstymasIGrupes(list<Studentas> &studentai, list<Studentas> &zemesniojoLygio, int &zemesnioL, int &aukstesnioL) {

    list<Studentas>::iterator it;

    for (it = studentai.begin(); it != studentai.end(); ++it) {
        if (it->galutinis < 5.00) {
            Studentas zemesnis;
            zemesnis.vardas = it->vardas;
            zemesnis.pavarde = it->pavarde;
            zemesnis.galutinis = it->galutinis;
            zemesniojoLygio.push_back(zemesnis);
            zemesnioL++;
            aukstesnioL--;
        }
    }
    studentai.remove_if(Palyginimas2);

}

bool Palyginimas2(Studentas studentas) {
    return studentas.galutinis < 5.00;
}

void LIST2Spausdinimas(int studentuSkaicius, list<Studentas> &studentai,
                       list<Studentas> &zemesniojoLygio, int zemesnioL, int aukstesnioL) {
    string zemesniujuPavadinimas = "ŽemesniojoLygioStudentaiLIST2_" + to_string(studentuSkaicius) + ".txt";
    ofstream zem(zemesniujuPavadinimas);
    string aukstesniujuPavadinimas = "AukštesniojoLygioStudentaiLIST2_" + to_string(studentuSkaicius) + ".txt";
    ofstream aukst(aukstesniujuPavadinimas);

    for (Studentas zemesnis : zemesniojoLygio) {
        zem << zemesnis.vardas << " " <<
            zemesnis.pavarde << " " << fixed << setprecision(2) <<
            zemesnis.galutinis << endl;
    }
    for (Studentas aukstesnis : studentai) {
        aukst << aukstesnis.vardas << " " <<
              aukstesnis.pavarde << " " << fixed << setprecision(2) <<
              aukstesnis.galutinis << endl;
    }
    zemesniojoLygio.clear();
    studentai.clear();
}