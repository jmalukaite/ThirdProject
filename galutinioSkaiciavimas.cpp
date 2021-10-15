#include "studentas.h"
#include "namuDarbuSkaiciavimas.h"

double GalutinioSkaiciavimas(Studentas studentas) {
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