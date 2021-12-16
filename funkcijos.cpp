#include "studentas.h"
#include "funkcijos.h"


void NuskaitymasKLASE(vector<Studentas> &studentai, int studentuSkaicius, int namuDarbuSkaicius) {
    studentai.reserve(studentuSkaicius);
    ifstream fd;
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);
//    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < studentuSkaicius; i++)
    {
        /** reads information about all students from a given file */
        Studentas laikinas;
        laikinas.readStudentas(fd, namuDarbuSkaicius);
        studentai.push_back(laikinas);
    }
    fd.close();

//    auto end = std::chrono::high_resolution_clock::now();
//    chrono::duration<double> diff = end - start;
//    cout << to_string(studentuSkaicius) << " studentų duomenų nuskaitymas "
//                                           "užtruko (naudojant class): " << diff.count() << " s\n";

}


void SkirstymasIGrupesKLASE(vector<Studentas> &studentai,
                            vector<Studentas> &aukstesniojoLygio, vector<Studentas> &zemesniojoLygio) {

//    auto start = std::chrono::high_resolution_clock::now();
    /** students are separated into groups according by their final grade */
    for (auto &i : studentai) {
        /** if a student has a grade lower than 5, he/she is put into a weaker studying group */
        if (i.getGalutinis() < 5.00) {
            zemesniojoLygio.push_back(i);
        }
        /** if the grade is higher, the student is put into a stronger studying group */
        else {
            aukstesniojoLygio.push_back(i);
        }
    }
//    auto end = std::chrono::high_resolution_clock::now();
//    chrono::duration<double> diff = end - start;
//    cout << "Studentų skirstymas į grupes užtruko (naudojant class): " << diff.count() << " s\n";
}

void SpausdinimasKLASE(int studentuSkaicius, const vector<Studentas> &aukstesniojoLygio,
                       const vector<Studentas> &zemesniojoLygio) {
    string zemesniujuPavadinimas = "ŽemesniojoLygioStudentai_klase" + to_string(studentuSkaicius) + ".txt";
    ofstream zem(zemesniujuPavadinimas);
    string aukstesniujuPavadinimas = "AukštesniojoLygioStudentai_klase" + to_string(studentuSkaicius) + ".txt";
    ofstream aukst(aukstesniujuPavadinimas);

    for (Studentas elementas:zemesniojoLygio) {
        zem << elementas.getVardas() << " " << elementas.getPavarde() << " "
        << fixed << setprecision(2) << elementas.getGalutinis() << endl;
    }
    for (Studentas elementas : aukstesniojoLygio) {
        aukst << elementas.getVardas() << " " << elementas.getPavarde() << " " << fixed << setprecision(2) <<
        elementas.getGalutinis() << endl;
    }
//    cout << "-------------------------------------------------------------------------" << endl;
}
