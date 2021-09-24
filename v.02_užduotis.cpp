#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <sstream>
#include <numeric>
#include <fstream>

using namespace std;
ifstream fd("/Users/jaune/Desktop/objektinis programavimas/v.02/kursiokai.txt");

struct Studentas {
    string vardas, pavarde;
    int ndSkaicius = 0;
    vector<int> namuDarbai;
    double namuDarbuSuma = 0;
    int egzaminas;
    double galutinis;
    double galutinisMediana;
    double galutinisVidurkis;
};

void DuomenuIvedimasIrSaugojimas(vector<Studentas> studentai, int &studentuSkaicius);

void StudentoDuomenuSuvedimasRanka(Studentas &studentas);

void NuskaitymasIsFailo(Studentas &studentas, int pazymiuSkaicius);

double PazymiuSkaiciavimasFaile(string const &str);

void PazymiuSuvedimasRanka(Studentas &studentas);

void AsitiktinisPazymiuSuvedimas(Studentas &studentas);

double NamuDarbuVidurkioSkaiciavimas(Studentas studentas);

double NamuDarbuMedianosSkaiciavimas(Studentas studentas);

double GalutinioSkaiciavimas(Studentas studentas);

void SpausdinimasIKonsole(Studentas studentas);

bool LyginimoOperacija(const Studentas &pirmas, const Studentas &antras);

void SpausdinimasIRezultatuFaila(const vector<Studentas> &studentai);


int main() {
    int studentuSkaicius = 0;
    vector<Studentas> studentai;
    studentai.reserve(10000);
    DuomenuIvedimasIrSaugojimas(studentai, studentuSkaicius);
    return 0;
}

void DuomenuIvedimasIrSaugojimas(vector<Studentas> studentai, int &studentuSkaicius) {
    char duomenuIvedimoBudas;
    cout << "Jei norite studento informaciją įvesti patys, tai spauskite 'P', o jei nuskaityti iš dokumento,"
            " tai spauskite 'F': ";

    while (true) {
        cin >> duomenuIvedimoBudas;
        if (duomenuIvedimoBudas != 'P' && duomenuIvedimoBudas != 'F') {
            cout << "Nėra tokio pasirinkimo, įveskite iš naujo: ";
        } else break;
    }
    if (duomenuIvedimoBudas == 'P') {
        cout << "Kurse besimokančių studentų skaičius: ";
        cin >> studentuSkaicius;
        for (int i = 0; i < studentuSkaicius; i++) {
            Studentas laikinas;
            StudentoDuomenuSuvedimasRanka(laikinas);
            laikinas.galutinis = GalutinioSkaiciavimas(laikinas);
            studentai.push_back(laikinas);
            laikinas.namuDarbai.clear();
        }
        for (const Studentas &st : studentai) {
            SpausdinimasIKonsole(st);
        }
    } else if (duomenuIvedimoBudas == 'F') {
        studentuSkaicius = 0;
        string pirmojiEilute;
        getline(fd, pirmojiEilute);
        double pazymiuSkaicius = PazymiuSkaiciavimasFaile(pirmojiEilute);
        while (!fd.eof()) {
            Studentas laikinas;
            NuskaitymasIsFailo(laikinas, pazymiuSkaicius);
            laikinas.galutinisVidurkis = 0.4 * NamuDarbuVidurkioSkaiciavimas(laikinas) + 0.6 * laikinas.egzaminas;
            laikinas.galutinisMediana = 0.4 * NamuDarbuMedianosSkaiciavimas(laikinas) + 0.6 * laikinas.egzaminas;
            studentai.push_back(laikinas);
            ++studentuSkaicius;
        }
        sort(studentai.begin(), studentai.end(), LyginimoOperacija);
        SpausdinimasIRezultatuFaila(studentai);

    }
}

void StudentoDuomenuSuvedimasRanka(Studentas &studentas) {
    cout << "Vardas ir pavardė: ";
    cin >> studentas.vardas >> studentas.pavarde;
    char pasirinkimas;

    cout << "Jei norite, kad pažymiai būtų suvesti atsitiktiniu būdu, tai spauskite 'A', o jei suvesti ranka,"
            " tai spauskite 'R': ";

    while (true) {
        cin >> pasirinkimas;
        if (pasirinkimas != 'A' && pasirinkimas != 'R') {
            cout << "Nėra tokio pasirinkimo, įveskite iš naujo: ";
        } else break;
    }

    if (pasirinkimas == 'A') {
        AsitiktinisPazymiuSuvedimas(studentas);
    } else if (pasirinkimas == 'R') {
        PazymiuSuvedimasRanka(studentas);
    }
}

void NuskaitymasIsFailo(Studentas &studentas, int pazymiuSkaicius) {
    studentas.namuDarbuSuma = 0;
    char vardas[14];
    char pavarde[24];
    fd.get(vardas, 14);
    studentas.vardas = vardas;
    fd.get(pavarde, 24);
    studentas.pavarde = pavarde;
    int ivestis;
    for (int i = 0; i < pazymiuSkaicius; i++) {
        fd >> ivestis;
        studentas.namuDarbai.push_back(ivestis);
        studentas.namuDarbuSuma += ivestis;
    }
    fd >> studentas.egzaminas;
    fd.clear();
    fd.ignore(256, '\n');
}

double PazymiuSkaiciavimasFaile(string const &stream) {
    stringstream streaming(stream);
    // Grąžina 'atstumą' tarp pirmo ir paskutinio elemento nuskaitytoje eilutėje,
    // atimame 3, kad rastume pažymių skaičių (atimame 3 elementus - vardą, pavardę bei egzaminoRezultatą)
    return distance(istream_iterator<string>(streaming), istream_iterator<string>()) - 3;
}

void PazymiuSuvedimasRanka(Studentas &studentas) {
    cout << "Namų darbų rezultatai (įveskite '0', kai suvedėte visus pažymius, ir paspauskite 'Enter'): ";
    int ivestis;
    while (cin >> ivestis) {
        if (ivestis != 0) {
            studentas.namuDarbai.push_back(ivestis);
            ++studentas.ndSkaicius;
            studentas.namuDarbuSuma = studentas.namuDarbuSuma + ivestis;
        } else break;
    }
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Egzamino ivertinimas: ";
    cin >> studentas.egzaminas;
}

void AsitiktinisPazymiuSuvedimas(Studentas &studentas) {
    srand(time(NULL));
    cout << "Kadangi buvo pasirinktas atsitiktinis pažymių įvedimas, įrašykite, kiek namų darbų atliko studentas: ";
    cin >> studentas.ndSkaicius;
    cout << "Sugeneruoti namų darbai: ";
    for (int i = 0; i < studentas.ndSkaicius; i++) {
        studentas.namuDarbai.push_back(rand() % 10 + 1);
        cout << studentas.namuDarbai.at(i) << " ";
    }
    cout << endl;
    studentas.egzaminas = rand() % 10 + 1;
    cout << "Egzamino ivertinimas: " << studentas.egzaminas << endl;
}

double NamuDarbuVidurkioSkaiciavimas(Studentas studentas) {
    double vidurkis =
            accumulate(studentas.namuDarbai.begin(), studentas.namuDarbai.end(), 0.0) / studentas.namuDarbai.size();
    return vidurkis;
}

double NamuDarbuMedianosSkaiciavimas(Studentas studentas) {
    double mediana;
    sort(studentas.namuDarbai.begin(), studentas.namuDarbai.end());
    int vidurinisElementas = studentas.namuDarbai.size() / 2;
    if (studentas.namuDarbai.size() / 2 == 0) {
        mediana = (studentas.namuDarbai[vidurinisElementas - 1] + studentas.namuDarbai[vidurinisElementas]) / 2.;
    } else {
        mediana = studentas.namuDarbai[vidurinisElementas];
    }
    return mediana;
}

double GalutinioSkaiciavimas(Studentas studentas) {
    char skaiciavimoBudas;
    double vidurkis = NamuDarbuVidurkioSkaiciavimas(studentas);
    double mediana = NamuDarbuMedianosSkaiciavimas(studentas);
    cout << "Jei norite galutinį balą skaičiuoti naudojant aritmetinį vidurkį, įveskite 'V', "
            "o jei norite skaičiuoti naudojant mediana, įveskite 'M': ";
    double galutinis;

    while (true) {
        cin >> skaiciavimoBudas;
        if (skaiciavimoBudas != 'V' && skaiciavimoBudas != 'M') {
            cout << "Nėra tokio pasirinkimo, įveskite iš naujo: ";
        } else break;
    }
    if (skaiciavimoBudas == 'V') {
        galutinis = vidurkis * 0.4 + studentas.egzaminas * 0.6;
    } else if (skaiciavimoBudas == 'M') {
        galutinis = mediana * 0.4 + studentas.egzaminas * 0.6;
    }
    return galutinis;
}

void SpausdinimasIKonsole(Studentas studentas) {
    cout << "Rezultatai:" << endl;
    cout << fixed;
    cout << setw(20) << left << studentas.vardas << setw(30) << left << studentas.pavarde <<
         setw(20) << left << setprecision(2) << studentas.galutinis << endl;
}

bool LyginimoOperacija(const Studentas &pirmas, const Studentas &antras) {
    // Pagal šį palyginimą vėliau rūšiuojami duomenys pagal pavardes
    return pirmas.pavarde < antras.pavarde;
}

void SpausdinimasIRezultatuFaila(const vector<Studentas> &studentai) {
    ofstream fr("/Users/jaune/Desktop/objektinis programavimas/v.02/kursiokai_rezultatai.txt");
    fr << "Vardas          " << "Pavarde               " << "GalutinisMed   " << "GalutinisVid" << endl;
    for (const Studentas &st : studentai) {
        fr << st.vardas << " " << st.pavarde << " " << setprecision(3) << st.galutinisMediana
           << "            " << setprecision(3) << st.galutinisVidurkis << endl;
    }
}