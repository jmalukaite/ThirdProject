#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>
#include <chrono>

using namespace std;
struct Studentas {
    string vardas, pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};

double NamuDarbuVidurkioSkaiciavimas(Studentas studentas);

void AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius);

void NuskaitymasIsFailo(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void SkirstymasIGrupes(vector<Studentas> &studentai,
                       vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio);

void Spausdinimas(int studentuSkaicius, const vector<Studentas> &aukstesniojoLygio,
                  const vector<Studentas> &zemesniojoLygio);

int main() {

    int namuDarbuSkaicius = 4;
    string pavadinimas;
    int studentuSkaiciai[5] = {1000, 10000, 100000, 1000000, 10000000};

    vector<Studentas> studentai;
    vector<Studentas> aukstesniojoLygio;
    vector<Studentas> zemesniojoLygio;

    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        AtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, namuDarbuSkaicius);
        NuskaitymasIsFailo(studentai, studentuSkaicius, namuDarbuSkaicius);
        SkirstymasIGrupes(studentai, aukstesniojoLygio, zemesniojoLygio);
        Spausdinimas(studentuSkaicius, aukstesniojoLygio, zemesniojoLygio);
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


void NuskaitymasIsFailo(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);
    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
    while (indeksas < studentuSkaicius) {
        studentai.resize(studentai.size() + 1);
        fd >> studentai.at(indeksas).vardas;
        fd >> studentai.at(indeksas).pavarde;
        int ivestis;
        for (int i = 0; i < namuDarbuSkaicius; i++) {
            fd >> ivestis;
            studentai.at(indeksas).namuDarbai.push_back(ivestis);
        }
        fd >> studentai.at(indeksas).egzaminas;
        studentai.at(indeksas).galutinis = NamuDarbuVidurkioSkaiciavimas(studentai.at(indeksas)) * 0.4
                                           + studentai.at(indeksas).egzaminas * 0.6;
        indeksas++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << to_string(studentuSkaicius) << " studentų duomenų nuskaitymas "
                                           "užtruko (naudojant vector): " << diff.count() << " s\n";
}

void SkirstymasIGrupes(vector<Studentas> &studentai,
                       vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio) {

    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
    for (auto &i : studentai) {
        if (i.galutinis < 5.00) {
            zemesniojoLygio.push_back(i);
        } else {
            aukstesniojoLygio.push_back(i);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Studentų skirstymas į grupes užtruko (naudojant vector): " << diff.count() << " s\n";
}

void Spausdinimas(int studentuSkaicius, const vector<Studentas> &aukstesniojoLygio,
                  const vector<Studentas> &zemesniojoLygio) {
    string zemesniujuPavadinimas = "ŽemesniojoLygioStudentai" + to_string(studentuSkaicius) + ".txt";
    ofstream zem(zemesniujuPavadinimas);
    string aukstesniujuPavadinimas = "AukštesniojoLygioStudentai" + to_string(studentuSkaicius) + ".txt";
    ofstream aukst(aukstesniujuPavadinimas);

//    auto start = std::chrono::high_resolution_clock::now();
//    auto startas = start;
    for (const auto &elementas:zemesniojoLygio) {
        zem << elementas.vardas << " " << elementas.pavarde << " "
            << fixed << setprecision(2) << elementas.galutinis << endl;
    }
    for (const auto &elementas : aukstesniojoLygio) {
        aukst << elementas.vardas << " " << elementas.pavarde << " " << fixed << setprecision(2) <<
              elementas.galutinis << endl;
    }
//    auto end = std::chrono::high_resolution_clock::now();
//    chrono::duration<double> diff = end - start;
//    cout << "Studentų spausdinimas į failus pagal grupes užtruko: " << diff.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;
}

