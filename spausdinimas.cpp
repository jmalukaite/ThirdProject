#include "studentas.h"

void SpausdinimasIKonsole(Studentas studentas) {
    std::cout << std::fixed;
    std::cout << std::setw(20) << std::left << studentas.vardas << std::setw(30) << std::left << studentas.pavarde <<
    std::setw(20) << std::left << std::setprecision(2) << studentas.galutinis << std::endl;
}

bool LyginimoOperacija(const Studentas &pirmas, const Studentas &antras) {
    // Pagal šį palyginimą vėliau rūšiuojami duomenys pagal pavardes
    return pirmas.pavarde < antras.pavarde;
}

void SpausdinimasIRezultatuFaila(const std::vector<Studentas> &studentai) {
    std::ofstream fr("/Users/jaune/Desktop/objektinis programavimas/v.02/kursiokai_rezultatai.txt");
    //fr << "Vardas          " << "Pavarde               " << "GalutinisMed   " << "GalutinisVid" << endl;
    for (const Studentas &st : studentai) {
        std::cout << st.vardas << " " << st.pavarde << " " << std::fixed << std::setprecision(2) << st.galutinisMediana
        << "  " << std::fixed << std::setprecision(2) << st.galutinisVidurkis << std::endl;
    }
}

