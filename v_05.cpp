#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>
#include <chrono>
#include <list>
#include <iterator>

using namespace std;
struct Studentas {
    string vardas, pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};

double NamuDarbuVidurkioSkaiciavimas(Studentas studentas);

void AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius);

void NuskaitymasIsFailo(list<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void SkirstymasIGrupes(list<Studentas> studentai, list<Studentas> &aukstesniojoLygio,
                       list<Studentas> &zemesniojoLygio, int &zemesnioL, int &aukstesnioL);

void Spausdinimas(int studentuSkaicius, list<Studentas> &aukstesniojoLygio,
                  list<Studentas> &zemesniojoLygio, int zemesnioL, int aukstesnioL);

int main() {

    int namuDarbuSkaicius = 4;
    string pavadinimas;
    int studentuSkaiciai[5] = {1000, 10000, 100000, 1000000, 10000000};

    list<Studentas> studentai;
    list<Studentas> aukstesniojoLygio;
    list<Studentas> zemesniojoLygio;

    int aukstesnioL = 0;
    int zemesnioL = 0;

    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        AtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, namuDarbuSkaicius);
        NuskaitymasIsFailo(studentai, studentuSkaicius, namuDarbuSkaicius);
        SkirstymasIGrupes(studentai, aukstesniojoLygio, zemesniojoLygio, zemesnioL, aukstesnioL);
        Spausdinimas(studentuSkaicius, aukstesniojoLygio, zemesniojoLygio, zemesnioL, aukstesnioL);
    }

    return 0;
}

double NamuDarbuVidurkioSkaiciavimas(Studentas studentas) {
    double vidurkis =
            accumulate(studentas.namuDarbai.begin(), studentas.namuDarbai.end(), 0.0) / studentas.namuDarbai.size();
    return vidurkis;
}


void AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius) {
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    ofstream stud(pavadinimas);
    srand(time(NULL));
//    auto start = std::chrono::high_resolution_clock::now();
//    auto startas = start;
    for (int i = 0; i < studentuSkaicius; i++) {
        stud << "Vardas" + to_string(i + 1) << " " << "Pavarde" + to_string(i + 1) << " ";
        for (int j = 0; j < namuDarbuSkaicius + 1; j++) { //+1 nes prisideda egzamino pazymys
            stud << rand() % 10 + 1 << " ";
        }
        stud << endl;
    }
//    auto end = std::chrono::high_resolution_clock::now();
//    chrono::duration<double> diff = end - start; // Skirtumas (s)
//    cout << to_string(studentuSkaicius) << " studentų duomenų generavimas "
//                                           "užtruko: " << diff.count() << " s\n";
}


void NuskaitymasIsFailo(list<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);
    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
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
        studentas.galutinis = NamuDarbuVidurkioSkaiciavimas(studentas) * 0.4
                              + studentas.egzaminas * 0.6;
        studentai.push_back(studentas);
        indeksas++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << to_string(studentuSkaicius) << " studentų duomenų nuskaitymas "
                                           "užtruko (naudojant list): " << diff.count() << " s\n";

}

void SkirstymasIGrupes(list<Studentas> studentai, list<Studentas> &aukstesniojoLygio,
                       list<Studentas> &zemesniojoLygio, int &zemesnioL, int &aukstesnioL) {

    list<Studentas>::iterator it;

    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;

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

    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Studentų skirstymas į grupes užtruko (naudojant list): " << diff.count() << " s\n";
}

void Spausdinimas(int studentuSkaicius, list<Studentas> &aukstesniojoLygio,
                  list<Studentas> &zemesniojoLygio, int zemesnioL, int aukstesnioL) {
    string zemesniujuPavadinimas = "ŽemesniojoLygioStudentai" + to_string(studentuSkaicius) + ".txt";
    ofstream zem(zemesniujuPavadinimas);
    string aukstesniujuPavadinimas = "AukštesniojoLygioStudentai" + to_string(studentuSkaicius) + ".txt";
    ofstream aukst(aukstesniujuPavadinimas);

//    auto start = std::chrono::high_resolution_clock::now();
//    auto startas = start;
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
//    auto end = std::chrono::high_resolution_clock::now();
//    chrono::duration<double> diff = end - start;
//    cout << "Studentų spausdinimas į failus pagal grupes užtruko: " << diff.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;
}