#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

struct Studentas {
    string vardas, pavarde;
    int ndSkaicius = 0;
    vector<int> namuDarbai;
    double namuDarbuSuma = 0;
    int egzaminas;
    double galutinis;
};

void StudentoDuomenuSuvedimas(Studentas &studentas);

double NamuDarbuVidurkioSkaiciavimas(Studentas studentas);

double NamuDarbuMedianosSkaiciavimas(Studentas studentas);

void AsitiktinisPazymiuSuvedimas(Studentas &studentas);

void PazymiuSuvedimasRanka(Studentas &studentas);

double GalutinioSkaiciavimas(Studentas studentas);

void Spausdinimas(Studentas studentas);

int main() {
    int studentuSkaicius;
    cout << "Kurse besimokančių studentų skaičius: ";
    cin >> studentuSkaicius;
    vector<Studentas> studentai;
    Studentas laikinas;
    studentai.reserve(studentuSkaicius);

    for (int i = 0; i < studentuSkaicius; i++) {
        StudentoDuomenuSuvedimas(laikinas);
        laikinas.galutinis = GalutinioSkaiciavimas(laikinas);
        studentai.push_back(laikinas);
        laikinas.namuDarbai.clear();
    }

    cout << setw(20) << left << "Studento vardas" << setw(30) << left << "Pavardė" << setw(20) << left <<
         "Galutinis balas" << endl;
    for (const Studentas &st : studentai) {
        Spausdinimas(st);
    }
    return 0;
}

void StudentoDuomenuSuvedimas(Studentas &studentas) {
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


void Spausdinimas(Studentas studentas) {
    cout << fixed;
    cout << setw(20) << left << studentas.vardas << setw(30) << left << studentas.pavarde <<
         setw(20) << left << setprecision(2) << studentas.galutinis << endl;
}


