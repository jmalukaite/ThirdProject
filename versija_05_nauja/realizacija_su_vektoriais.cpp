#include "libraries.h"
#include "realizacija_su_vektoriais.h"

double NamuDarbuVidurkioSkaiciavimasVECTOR(Studentas studentas) {
    double vidurkis =
            accumulate(studentas.namuDarbai.begin(), studentas.namuDarbai.end(), 0.0) / studentas.namuDarbai.size();
    return vidurkis;
}


void NuskaitymasIsFailoVECTOR(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);
    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
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
        studentai.at(indeksas).galutinis = NamuDarbuVidurkioSkaiciavimasVECTOR(studentai.at(indeksas)) * 0.4
                + studentai.at(indeksas).egzaminas * 0.6;
        indeksas++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Duomenų nuskaitymas užtruko (naudojant vector): " << diff.count() << " s\n";
}

void SkirstymasIGrupesVECTOR(vector<Studentas> &studentai,
                       vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio) {

    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
    for (auto &i : studentai) {
        if (i.galutinis < 5.00) {
            zemesniojoLygio.push_back(i);
        } else {
            aukstesniojoLygio.push_back(i);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Skirstymas į grupes užtruko (naudojant vector): " << diff.count() << " s\n";
}

void SpausdinimasVECTOR(int studentuSkaicius, const vector<Studentas> &aukstesniojoLygio,
                  const vector<Studentas> &zemesniojoLygio) {
    string zemesniujuPavadinimas = "ŽemesniojoLygioStudentai" + to_string(studentuSkaicius) + ".txt";
    ofstream zem(zemesniujuPavadinimas);
    string aukstesniujuPavadinimas = "AukštesniojoLygioStudentai" + to_string(studentuSkaicius) + ".txt";
    ofstream aukst(aukstesniujuPavadinimas);

    for (const auto &elementas:zemesniojoLygio) {
        zem << elementas.vardas << " " << elementas.pavarde << " "
        << fixed << setprecision(2) << elementas.galutinis << endl;
    }
    for (const auto &elementas : aukstesniojoLygio) {
        aukst << elementas.vardas << " " << elementas.pavarde << " " << fixed << setprecision(2) <<
        elementas.galutinis << endl;
    }
}

