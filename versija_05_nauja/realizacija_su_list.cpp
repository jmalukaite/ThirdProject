#include "libraries.h"
#include "realizacija_su_list.h"

double NamuDarbuVidurkioSkaiciavimasLIST(Studentas studentas) {
    double vidurkis =
            accumulate(studentas.namuDarbai.begin(), studentas.namuDarbai.end(), 0.0) / studentas.namuDarbai.size();
    return vidurkis;
}


void NuskaitymasIsFailoLIST(list<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);
    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
    while (indeksas < studentuSkaicius) {
        Studentas studentas;
        fd >> studentas.vardas;
        fd >> studentas.pavarde;
        int ivestis;
        for (int i = 0; i < namuDarbuSkaicius; i++) {
            fd >> ivestis;
            studentas.namuDarbai.push_back(ivestis);
        }
        fd >> studentas.egzaminas;
        studentas.galutinis = NamuDarbuVidurkioSkaiciavimasLIST(studentas) * 0.4
                + studentas.egzaminas * 0.6;
        studentai.push_back(studentas);
        indeksas++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Duomenų nuskaitymas užtruko (naudojant list): " << diff.count() << " s\n";

}

void SkirstymasIGrupesLIST(list<Studentas> &studentai, list<Studentas> &aukstesniojoLygio,
                       list<Studentas> &zemesniojoLygio) {

    list<Studentas>::iterator it;

    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;

    for (it = studentai.begin(); it != studentai.end(); ++it) {
        if (it->galutinis < 5.00) {
            Studentas zemesnis;
            zemesnis.vardas = it->vardas;
            zemesnis.pavarde = it->pavarde;
            zemesnis.galutinis = it->galutinis;
            zemesniojoLygio.push_back(zemesnis);

        } else {
            Studentas aukstesnis;
            aukstesnis.vardas = it->vardas;
            aukstesnis.pavarde = it->pavarde;
            aukstesnis.galutinis = it->galutinis;
            aukstesniojoLygio.push_back(aukstesnis);

        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Skirstymas į grupes užtruko (naudojant list): " << diff.count() << " s\n";
}

void SpausdinimasLIST(int studentuSkaicius, list<Studentas> &aukstesniojoLygio,
                  list<Studentas> &zemesniojoLygio) {
    string zemesniujuPavadinimas = "ŽemesniojoLygioStudentai" + to_string(studentuSkaicius) + ".txt";
    ofstream zem(zemesniujuPavadinimas);
    string aukstesniujuPavadinimas = "AukštesniojoLygioStudentai" + to_string(studentuSkaicius) + ".txt";
    ofstream aukst(aukstesniujuPavadinimas);

    for (Studentas zemesnis : zemesniojoLygio) {
        zem << zemesnis.vardas << " " <<
        zemesnis.pavarde << " " << fixed << setprecision(2) <<
        zemesnis.galutinis << endl;
    }
    for (Studentas aukstesnis : aukstesniojoLygio) {
        aukst << aukstesnis.vardas << " " <<
        aukstesnis.pavarde << " " << fixed << setprecision(2) <<
        aukstesnis.galutinis << endl;
    }
    zemesniojoLygio.clear();
    aukstesniojoLygio.clear();
    cout << "-------------------------------------------------------------------------" << endl;
}