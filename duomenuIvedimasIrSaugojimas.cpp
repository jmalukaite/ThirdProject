#include "studentas.h"
#include "galutinioSkaiciavimas.h"
#include "pazymiuSkaiciavimasFaile.h"
#include "duomenuIvedimasIrSaugojimas.h"
#include "namuDarbuSkaiciavimas.h"
#include "pazymiuSuvedimas.h"
#include "spausdinimas.h"

std::ifstream fd("/Users/jaune/Desktop/objektinis programavimas/v.02/studentai10000.txt");

void DuomenuIvedimasIrSaugojimas(std::vector<Studentas> studentai, int &studentuSkaicius) {
    char duomenuIvedimoBudas;
    std::cout << "Jei norite studento informaciją įvesti patys, tai spauskite 'P', o jei nuskaityti iš dokumento,"
                 " tai spauskite 'F': ";

    while (true) {
        std::cin >> duomenuIvedimoBudas;
        if (duomenuIvedimoBudas != 'P' && duomenuIvedimoBudas != 'F') {
            std::cout << "Nėra tokio pasirinkimo, įveskite iš naujo: ";
        } else break;
    }
    if (duomenuIvedimoBudas == 'P') {
        std::cout << "Kurse besimokančių studentų skaičius: ";
        std::cin >> studentuSkaicius;
        for (int i = 0; i < studentuSkaicius; i++) {
            Studentas laikinas;
            StudentoDuomenuSuvedimasRanka(laikinas);
            laikinas.galutinis = GalutinioSkaiciavimas(laikinas);
            studentai.push_back(laikinas);
            laikinas.namuDarbai.clear();
        }
        std::cout << "Rezultatai:" << std::endl;
        for (const Studentas &st : studentai) {
            SpausdinimasIKonsole(st);
        }
    } else if (duomenuIvedimoBudas == 'F') {
        studentuSkaicius = 0;

        try {
            if (!fd.is_open())
                throw 0;
            std::string pirmojiEilute;
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
        }
        catch (int erroras) {
            std::cerr << "Neteisingai pasirinktas dokumentas " << erroras << std::endl;
        }
        sort(studentai.begin(), studentai.end(), LyginimoOperacija);
        SpausdinimasIRezultatuFaila(studentai);

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

void StudentoDuomenuSuvedimasRanka(Studentas &studentas) {
    std::cout << "Vardas ir pavardė: ";
    std::cin >> studentas.vardas >> studentas.pavarde;
    char pasirinkimas;

    std::cout << "Jei norite, kad pažymiai būtų suvesti atsitiktiniu būdu, tai spauskite 'A', o jei suvesti ranka,"
                 " tai spauskite 'R': ";

    while (true) {
        std::cin >> pasirinkimas;
        if (pasirinkimas != 'A' && pasirinkimas != 'R') {
            std::cout << "Nėra tokio pasirinkimo, įveskite iš naujo: ";
        } else break;
    }

    if (pasirinkimas == 'A') {
        AsitiktinisPazymiuSuvedimas(studentas);
    } else if (pasirinkimas == 'R') {
        try
        {
            PazymiuSuvedimasRanka(studentas);
        }
        catch( const std::invalid_argument& e )
        {
            std::cerr << "exception: " << e.what() << std::endl;
        }
    }
}