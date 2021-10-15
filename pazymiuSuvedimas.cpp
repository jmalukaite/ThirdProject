#include "studentas.h"

void AsitiktinisPazymiuSuvedimas(Studentas &studentas) {
    srand(time(NULL));
    std::cout << "Kadangi buvo pasirinktas atsitiktinis pažymių įvedimas, įrašykite, kiek namų darbų atliko studentas: ";
    std::cin >> studentas.ndSkaicius;
    std::cout << "Sugeneruoti namų darbai: ";
    for (int i = 0; i < studentas.ndSkaicius; i++) {
        studentas.namuDarbai.push_back(rand() % 10 + 1);
        std::cout << studentas.namuDarbai.at(i) << " ";
    }
    std::cout << std::endl;
    studentas.egzaminas = rand() % 10 + 1;
    std::cout << "Egzamino ivertinimas: " << studentas.egzaminas << std::endl;
}

void PazymiuSuvedimasRanka(Studentas &studentas) {
    std::cout << "Namų darbų rezultatai (įveskite '0', kai suvedėte visus pažymius, ir paspauskite 'Enter'): ";
    int ivestis;
    while (std::cin >> ivestis) {
        if (ivestis < 0)
        {
            throw std::invalid_argument("Namų darbai privalo būti teigiami!");
        }
        if (ivestis != 0) {
            studentas.namuDarbai.push_back(ivestis);
            ++studentas.ndSkaicius;
            studentas.namuDarbuSuma = studentas.namuDarbuSuma + ivestis;
        } else break;
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    std::cout << "Egzamino ivertinimas: ";
    std::cin >> studentas.egzaminas;
}