#include "libraries.h"
#include "1strategija_vector.h"
double VECTORNamuDarbuVidurkioSkaiciavimas(Studentas studentas) {
    double vidurkis =
            accumulate(studentas.namuDarbai.begin(), studentas.namuDarbai.end(), 0.0) / studentas.namuDarbai.size();
    return vidurkis;
}
void VECTORAtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius) {
    string pavadinimas = "StudentaiVECTOR" + to_string(studentuSkaicius) + ".txt";
    ofstream stud(pavadinimas);
    srand(time(NULL));

    for (int i = 0; i < studentuSkaicius; i++) {
        stud << "Vardas" + to_string(i + 1) << " " << "Pavarde" + to_string(i + 1) << " ";
        for (int j = 0; j < namuDarbuSkaicius + 1; j++) { //+1 nes prisideda egzamino pazymys
            stud << rand() % 10 + 1 << " ";
        }
        stud << endl;
    }
}

void VECTORNuskaitymasIsFailo(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "StudentaiVECTOR" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);

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
        studentai.at(indeksas).galutinis = VECTORNamuDarbuVidurkioSkaiciavimas(studentai.at(indeksas)) * 0.4
                + studentai.at(indeksas).egzaminas * 0.6;
        indeksas++;
    }
}

void VECTORSkirstymasIGrupes(vector<Studentas> &studentai,
                       vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio) {

    for (auto &i : studentai) {
        if (i.galutinis < 5.00) {
            zemesniojoLygio.push_back(i);
        } else {
            aukstesniojoLygio.push_back(i);
        }
    }
}

void VECTORSpausdinimas(int studentuSkaicius, const vector<Studentas> &aukstesniojoLygio,
                  const vector<Studentas> &zemesniojoLygio) {
    string zemesniujuPavadinimas = "ŽemesniojoLygioStudentaiVECTOR" + to_string(studentuSkaicius) + ".txt";
    ofstream zem(zemesniujuPavadinimas);
    string aukstesniujuPavadinimas = "AukštesniojoLygioStudentaiVECTOR" + to_string(studentuSkaicius) + ".txt";
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
