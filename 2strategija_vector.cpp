#include "libraries.h"
#include "2strategija_vector.h"

double VECTOR2NamuDarbuVidurkioSkaiciavimas(Studentas studentas) {
    double vidurkis =
            accumulate(studentas.namuDarbai.begin(), studentas.namuDarbai.end(), 0.0) / studentas.namuDarbai.size();
    return vidurkis;
}

void VECTOR2AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &namuDarbuSkaicius) {
    string pavadinimas = "StudentaiVECTOR2_" + to_string(studentuSkaicius) + ".txt";
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

void VECTOR2NuskaitymasIsFailo(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "StudentaiVECTOR2_" + to_string(studentuSkaicius) + ".txt";
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
        studentai.at(indeksas).galutinis = VECTOR2NamuDarbuVidurkioSkaiciavimas(studentai.at(indeksas)) * 0.4
                                           + studentai.at(indeksas).egzaminas * 0.6;
        indeksas++;
    }
}

void VECTOR2SkirstymasIGrupes(vector<Studentas> &studentai, vector<Studentas> &zemesniojoLygio) {

    for (auto it = studentai.begin(); it != studentai.end(); ++it) {
        if (it->galutinis < 5.00) {
            zemesniojoLygio.push_back(*it);
        }
    }
    remove_if(studentai.begin(), studentai.end(), Palyginimas);
}

bool Palyginimas(Studentas studentas) {
    return studentas.galutinis < 5.00;
}

void VECTOR2Spausdinimas(int studentuSkaicius, const vector<Studentas> &studentai,
                         const vector<Studentas> &zemesniojoLygio) {
    string zemesniujuPavadinimas = "ŽemesniojoLygioStudentaiVECTOR2_" + to_string(studentuSkaicius) + ".txt";
    ofstream zem(zemesniujuPavadinimas);
    string aukstesniujuPavadinimas = "AukštesniojoLygioStudentaiVECTOR2_" + to_string(studentuSkaicius) + ".txt";
    ofstream aukst(aukstesniujuPavadinimas);

    for (const auto &elementas:zemesniojoLygio) {
        zem << elementas.vardas << " " << elementas.pavarde << " "
            << fixed << setprecision(2) << elementas.galutinis << endl;
    }
    for (const auto &elementas : studentai) {
        aukst << elementas.vardas << " " << elementas.pavarde << " " << fixed << setprecision(2) <<
              elementas.galutinis << endl;
    }

}
