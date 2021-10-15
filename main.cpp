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

//ofstream fr("greicioAnalize.txt");

double NamuDarbuVidurkioSkaiciavimas(Studentas studentas);

//double NamuDarbuMedianosSkaiciavimas(Studentas studentas);

void AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius);

void NuskaitymasIsFailo(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius);

void SkirstymasIGrupes(int studentuSkaicius, vector<Studentas> &studentai,
                       vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio);

void Spausdinimas(int studentuSkaicius, const vector<Studentas>& aukstesniojoLygio,
                  const vector<Studentas>& zemesniojoLygio);

int main() {

    int namuDarbuSkaicius = 4;
    string pavadinimas;
    int studentuSkaiciai[5] = {1000, 10000, 100000, 1000000, 10000000};

    vector<Studentas> studentai;
    //studentai.reserve(studentuSkaicius);

    vector<Studentas> aukstesniojoLygio;
    //aukstesniojoLygio.reserve(aukstesnieji);
    vector<Studentas> zemesniojoLygio;
    //zemesniojoLygio.reserve(zemesnieji);

    for (int i : studentuSkaiciai)
    {
        int studentuSkaicius = i;
        AtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, namuDarbuSkaicius);
        NuskaitymasIsFailo(studentai, studentuSkaicius, namuDarbuSkaicius);
        SkirstymasIGrupes(studentuSkaicius, studentai,
                          aukstesniojoLygio, zemesniojoLygio);
        Spausdinimas(studentuSkaicius, aukstesniojoLygio, zemesniojoLygio);
    }

    return 0;
}


double NamuDarbuVidurkioSkaiciavimas(Studentas studentas) {
    double vidurkis =
            accumulate(studentas.namuDarbai.begin(), studentas.namuDarbai.end(), 0.0) / studentas.namuDarbai.size();
    return vidurkis;
}

//double NamuDarbuMedianosSkaiciavimas(Studentas studentas) {
//    double mediana;
//    sort(studentas.namuDarbai.begin(), studentas.namuDarbai.end());
//    int vidurinisElementas = studentas.namuDarbai.size() / 2;
//    if (studentas.namuDarbai.size() / 2 == 0) {
//        mediana = (studentas.namuDarbai[vidurinisElementas - 1] + studentas.namuDarbai[vidurinisElementas]) / 2.;
//    } else {
//        mediana = studentas.namuDarbai[vidurinisElementas];
//    }
//    return mediana;
//}


void AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius) {
//    cout << "Įveskite norimą kiekį studentų: ";
//    cin >> studentuSkaicius;
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    ofstream stud(pavadinimas);
//    cout << "Įveskite, kiek buvo užduota namų darbų: ";
//    cin >> namuDarbuSkaicius;
    srand(time(NULL));
    auto start = std::chrono::high_resolution_clock::now(); auto startas = start;
    for (int i = 0; i < studentuSkaicius; i++) {
        stud << "Vardas" + to_string(i + 1) << " " << "Pavarde" + to_string(i + 1) << " ";
        for (int j = 0; j < namuDarbuSkaicius + 1; j++) { //+1 nes prisideda egzamino pazymys
            stud << rand() % 10 + 1 << " ";
        }
        stud << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << to_string(studentuSkaicius) << " studentų duomenų generavimas "
                                                       "užtruko: " << diff.count() << " s\n";
}


void NuskaitymasIsFailo(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);
    auto start = std::chrono::high_resolution_clock::now(); auto startas = start;
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
        indeksas++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    cout << to_string(studentuSkaicius) << " studentų duomenų nuskaitymas "
                                                "užtruko: " << diff.count() << " s\n";

}

void SkirstymasIGrupes(int studentuSkaicius, vector<Studentas> &studentai,
                       vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio) {
//    char baloTipas;
//    cout << "Jei norite, kad studentai būtų suskirstyti pagal medianinį galutinį balą, įveskite 'M',"
//            "o jei pagal vidurkį, įveskite 'V': ";
//    while (true) {
//        cin >> baloTipas;
//        if (baloTipas != 'M' && baloTipas != 'V') {
//            cout << "Nėra tokio pasirinkimo, įveskite iš naujo: ";
//        } else break;
//    }
//    if (baloTipas == 'M') {
//        for (int i = 0; i < studentuSkaicius; i++) {
//            studentai.at(i).galutinis = NamuDarbuMedianosSkaiciavimas(studentai.at(i)) * 0.4
//                                        + studentai.at(i).egzaminas * 0.6;
//        }
//    } else if (baloTipas == 'V') {
        for (int i = 0; i < studentuSkaicius; i++) {
            studentai.at(i).galutinis = NamuDarbuVidurkioSkaiciavimas(studentai.at(i)) * 0.4
                                        + studentai.at(i).egzaminas * 0.6;
        }
//    }
    auto start = std::chrono::high_resolution_clock::now(); auto startas = start;
    for (auto & i : studentai) {
        if (i.galutinis < 5.00) {
            zemesniojoLygio.push_back(i);
        } else {
            aukstesniojoLygio.push_back(i);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    cout << "Studentų skirstymas į grupes užtruko: " << diff.count() << " s\n";
}

void Spausdinimas(int studentuSkaicius, const vector<Studentas>& aukstesniojoLygio,
                  const vector<Studentas>& zemesniojoLygio) {
    string zemesniujuPavadinimas = "ŽemesniojoLygioStudentai" + to_string(studentuSkaicius) + ".txt";
    ofstream zem(zemesniujuPavadinimas);
    string aukstesniujuPavadinimas = "AukštesniojoLygioStudentai" + to_string(studentuSkaicius) + ".txt";
    ofstream aukst(aukstesniujuPavadinimas);

    auto start = std::chrono::high_resolution_clock::now(); auto startas = start;
    for (const auto &elementas:zemesniojoLygio) {
        zem << elementas.vardas << " " << elementas.pavarde << " "
        << fixed << setprecision(2) << elementas.galutinis << endl;
    }
    for (const auto &elementas : aukstesniojoLygio) {
        aukst << elementas.vardas << " " << elementas.pavarde << " " << fixed << setprecision(2) <<
        elementas.galutinis << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    cout << "Studentų spausdinimas į failus pagal grupes užtruko: " << diff.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;
}

