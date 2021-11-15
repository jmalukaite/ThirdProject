#include "libraries.h"
#include "DinaminioMasyvoGeneravimas.h"


// HINTAI KAIP DINAMISKAI KEISTI MASYVO DYDI
//Allocate a new[] array and store it in a temporary pointer.
//Copy over the previous values that you want to keep.
//Delete[] the old array.
//Change the member variables, ptr and size to point to the new array and hold the new size.


void StudentoDuomenuSuvedimas(Studentas &studentas);

double NamuDarbuVidurkioSkaiciavimas(const Studentas &studentas);

double NamuDarbuMedianosSkaiciavimas(const Studentas& studentas);

void AsitiktinisPazymiuSuvedimas(Studentas &studentas);

void PazymiuSuvedimasRanka(Studentas &studentas);

double GalutinioSkaiciavimas(const Studentas &studentas);

void Spausdinimas(int studentuSkaicius, Studentas studentai[]);

int main() {
    int studentuSkaicius;
    std::cout << "Kurse besimokančių studentų skaičius: ";
    std::cin >> studentuSkaicius;
    Studentas* studentai = new Studentas[studentuSkaicius];
    studentai = DinaminioMasyvoGeneravimas(studentai, studentuSkaicius);
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
    std::cout << "Vardas ir pavardė: ";
    std::cin >> studentas.vardas >> studentas.pavarde;
    char pasirinkimas;
    std::cout << "Jei norite, kad pažymiai būtų suvesti atsitiktiniu būdu, tai spauskite 'A', o jei suvesti ranka,"
            " tai spauskite 'R': ";

    // ciklas vykdomas tol, kol įvedamas sąlygas atitinkantis kintamasis
    while (true) {
        std::cin >> pasirinkimas;
        if (pasirinkimas != 'A' && pasirinkimas != 'R') {
            std::cout << "Nėra tokio pasirinkimo, įveskite iš naujo: ";
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
    std::cout << "Namų darbų rezultatai (įveskite '0', kai suvedėte visus pažymius, ir paspauskite 'Enter'): ";

    while (std::cin >> studentas.namuDarbai[studentas.ndSkaicius]) {
        if (studentas.namuDarbai[studentas.ndSkaicius] != 0) {
            studentas.namuDarbuSuma = studentas.namuDarbuSuma + studentas.namuDarbai[studentas.ndSkaicius];
            ++studentas.ndSkaicius;
            studentas.namuDarbai = NamuDarbuMasyvoGeneravimas(studentas.namuDarbai, studentas.ndSkaicius);
        } else break;
    }

    std::cout << "Egzamino ivertinimas: ";
    std::cin >> studentas.egzaminas;
}

void AsitiktinisPazymiuSuvedimas(Studentas &studentas) {
    srand(time(NULL));
    std::cout << "Kadangi buvo pasirinktas atsitiktinis pažymių įvedimas, įrašykite, kiek namų darbų atliko studentas: ";
    std::cin >> studentas.ndSkaicius;
    studentas.namuDarbai = NamuDarbuMasyvoGeneravimas(studentas.namuDarbai, studentas.ndSkaicius);
    std::cout << "Sugeneruoti namų darbai: ";
    for (int i = 0; i < studentas.ndSkaicius; i++) {
        studentas.namuDarbai[i] = rand() % 10 + 1;
        studentas.namuDarbuSuma = studentas.namuDarbuSuma + studentas.namuDarbai[i];
        std::cout << studentas.namuDarbai[i] << " ";
    }
    std::cout << std::endl;
    studentas.egzaminas = rand() % 10 + 1;
    std::cout << "Egzamino ivertinimas: " << studentas.egzaminas << std::endl;
}

double NamuDarbuVidurkioSkaiciavimas(const Studentas &studentas) {
    return studentas.namuDarbuSuma / studentas.ndSkaicius;
}

double NamuDarbuMedianosSkaiciavimas(const Studentas& studentas) {
    double mediana;
    // Pirmiausia išsirikiuojame duomenis, kad būtų randami viduriniai elementai
    std::sort(studentas.namuDarbai, studentas.namuDarbai + studentas.ndSkaicius);
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
    std::cout << "Jei norite galutinį balą skaičiuoti naudojant aritmetinį vidurkį, įveskite 'V', "
            "o jei norite skaičiuoti naudojant mediana, įveskite 'M': ";
    double galutinis;

    while (true) {
        std::cin >> skaiciavimoBudas;
        if (skaiciavimoBudas != 'V' && skaiciavimoBudas != 'M') {
            std::cout << "Nėra tokio pasirinkimo, įveskite iš naujo: ";
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
    std::cout << std::setw(20) << std::left << "Studento vardas" << std::setw(30) << std::left << "Pavardė"
    << std::setw(20) << std::left << "Galutinis balas" << std::endl;

    for (int i = 0; i < studentuSkaicius; i++) {
        std::cout << std::fixed;
        std::cout << std::setw(20) << std::left << studentai[i].vardas << std::setw(30) << std::left << studentai[i].pavarde <<
        std::setw(20) << std::left << std::setprecision(2) << studentai[i].galutinis << std::endl;
    }
}

