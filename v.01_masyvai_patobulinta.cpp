#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <random>

using namespace std;

struct Studentas {
    string vardas, pavarde;
    int ndSkaicius = 0;
    int *namuDarbai = new int[ndSkaicius];
    double namuDarbuSuma = 0;
    int egzaminas;
    double galutinis;
};

void StudentoDuomenuSuvedimas(Studentas &studentas);

double NamuDarbuVidurkioSkaiciavimas(const Studentas &studentas);

double NamuDarbuMedianosSkaiciavimas(const Studentas& studentas);

void AsitiktinisPazymiuSuvedimas(Studentas &studentas);

void PazymiuSuvedimasRanka(Studentas &studentas);

double GalutinioSkaiciavimas(const Studentas &studentas);

void Spausdinimas(int studentuSkaicius, Studentas studentai[]);

int main() {
    int studentuSkaicius;
    cout << "Kurse besimokančių studentų skaičius: ";
    cin >> studentuSkaicius;
    auto *studentai = new Studentas[studentuSkaicius];

    // Sukant ciklą suvedame reikalingus duomenis apie studentą ir apskaičiuojame jo galutinį balą
    for (int i = 0; i < studentuSkaicius; i++) {
        StudentoDuomenuSuvedimas(studentai[i]);
        studentai[i].galutinis = GalutinioSkaiciavimas(studentai[i]);
    }
    Spausdinimas(studentuSkaicius, studentai);
    delete[] studentai;
    return 0;
}

void StudentoDuomenuSuvedimas(Studentas &studentas) {
    cout << "Vardas ir pavardė: ";
    cin >> studentas.vardas >> studentas.pavarde;
    char pasirinkimas;
    cout << "Jei norite, kad pažymiai būtų suvesti atsitiktiniu būdu, tai spauskite 'A', o jei suvesti ranka,"
            " tai spauskite 'R': ";

    // ciklas vykdomas tol, kol įvedamas sąlygas atitinkantis kintamasis
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
    delete[] studentas.namuDarbai;
}

void PazymiuSuvedimasRanka(Studentas &studentas) {
    // Kadangi Mac'o operacinėje sistemoje enter yra laikomas white space'u,
    // tai ciklą turėtų būti galima užbaigti CNTRL-D, tačiau CLion nesupportina tokios operacijos (anot Stackoverflow)
    cout << "Namų darbų rezultatai (įveskite '0', kai suvedėte visus pažymius, ir paspauskite 'Enter'): ";

    while (cin >> studentas.namuDarbai[studentas.ndSkaicius]) {
        if (studentas.namuDarbai[studentas.ndSkaicius] != 0) {
            studentas.namuDarbuSuma = studentas.namuDarbuSuma + studentas.namuDarbai[studentas.ndSkaicius];
            ++studentas.ndSkaicius;
        } else break;
    }

    cout << "Egzamino ivertinimas: ";
    cin >> studentas.egzaminas;
}

void AsitiktinisPazymiuSuvedimas(Studentas &studentas) {
    srand(time(NULL));
    cout << "Kadangi buvo pasirinktas atsitiktinis pažymių įvedimas, įrašykite, kiek namų darbų atliko studentas: ";
    cin >> studentas.ndSkaicius;
    cout << "Sugeneruoti namų darbai: ";
    for (int i = 0; i < studentas.ndSkaicius; i++) {
        studentas.namuDarbai[i] = rand() % 10 + 1;
        studentas.namuDarbuSuma = studentas.namuDarbuSuma + studentas.namuDarbai[i];
        cout << studentas.namuDarbai[i] << " ";
    }
    cout << endl;
    studentas.egzaminas = rand() % 10 + 1;
    cout << "Egzamino ivertinimas: " << studentas.egzaminas << endl;
}

double NamuDarbuVidurkioSkaiciavimas(const Studentas &studentas) {
    return studentas.namuDarbuSuma / studentas.ndSkaicius;
}

double NamuDarbuMedianosSkaiciavimas(const Studentas& studentas) {
    double mediana;
    // Pirmiausia išsirikiuojame duomenis, kad būtų randami viduriniai elementai
    sort(studentas.namuDarbai, studentas.namuDarbai + studentas.ndSkaicius);
    int vidurinisElementas = studentas.ndSkaicius / 2;
    if (studentas.ndSkaicius % 2 == 0) {
        mediana = (studentas.namuDarbai[vidurinisElementas - 1] + studentas.namuDarbai[vidurinisElementas]) / 2.;
    } else {
        mediana = studentas.namuDarbai[(studentas.ndSkaicius + 1) / 2 - 1];
    }
    return mediana;
}

double GalutinioSkaiciavimas(const Studentas &studentas) {
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

void Spausdinimas(int studentuSkaicius, Studentas studentai[]) {
    cout << setw(20) << left << "Studento vardas" << setw(30) << left << "Pavardė" << setw(20) << left <<
         "Galutinis balas" << endl;

    for (int i = 0; i < studentuSkaicius; i++) {
        cout << fixed;
        cout << setw(20) << left << studentai[i].vardas << setw(30) << left << studentai[i].pavarde <<
             setw(20) << left << setprecision(2) << studentai[i].galutinis << endl;
    }
}

