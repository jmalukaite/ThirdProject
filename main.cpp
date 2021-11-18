#include "libraries.h"
#include "1strategija_list.h"
#include "1strategija_vector.h"
#include "2strategija_vector.h"
#include "2strategija_list.h"

int main() {

    int namuDarbuSkaicius = 4;
    string pavadinimas;
    int studentuSkaiciai[1] = {100000};


    cout << "PIRMOS STRATEGIJOS ANALIZE" << endl;

//    LIST
    cout << "LIST:" << endl;
    list<Studentas> studentai;
    list<Studentas> aukstesniojoLygio;
    list<Studentas> zemesniojoLygio;

    int aukstesnioL = 0;
    int zemesnioL = 0;
    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        LISTAtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, namuDarbuSkaicius);
        LISTNuskaitymasIsFailo(studentai, studentuSkaicius, namuDarbuSkaicius);
        LISTSkirstymasIGrupes(studentai, aukstesniojoLygio, zemesniojoLygio, zemesnioL, aukstesnioL);
        LISTSpausdinimas(studentuSkaicius, aukstesniojoLygio, zemesniojoLygio, zemesnioL, aukstesnioL);
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Programos veikimo sparta naudojant PIRMĄ strategiją su list: " << diff.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;


//    VECTOR
    vector<Studentas> studentaiVector;
    vector<Studentas> aukstesniojoLygioVector;
    vector<Studentas> zemesniojoLygioVector;

    cout << "VECTOR:" << endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    auto startas2 = start2;
    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        VECTORAtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, namuDarbuSkaicius);
        VECTORNuskaitymasIsFailo(studentaiVector, studentuSkaicius, namuDarbuSkaicius);
        VECTORSkirstymasIGrupes(studentaiVector, aukstesniojoLygioVector, zemesniojoLygioVector);
        VECTORSpausdinimas(studentuSkaicius, aukstesniojoLygioVector, zemesniojoLygioVector);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff2 = end2 - start2;
    cout << "Programos veikimo sparta naudojant PIRMĄ strategiją su vector: " << diff2.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;


//------------------------------------------------------------------------------------------------------------
//ANTRA STRATEGIJA

    cout << "ANTROS STRATEGIJOS ANALIZE" << endl;

    //    LIST
    cout << "LIST:" << endl;

    list<Studentas> studentaiLIST2;
    list<Studentas> zemesniojoLygioLIST2;

    int zemesnioL2 = 0;
    auto startlist2 = std::chrono::high_resolution_clock::now();
    auto startaslist2 = startlist2;
    for (int i : studentuSkaiciai) {
        int aukstesnioL2 = i;
        int studentuSkaicius = i;
        LIST2AtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, namuDarbuSkaicius);
        LIST2NuskaitymasIsFailo(studentaiLIST2, studentuSkaicius, namuDarbuSkaicius);
        LIST2SkirstymasIGrupes(studentaiLIST2, zemesniojoLygioLIST2, zemesnioL2, aukstesnioL2);
        LIST2Spausdinimas(studentuSkaicius, studentaiLIST2, zemesniojoLygioLIST2, zemesnioL2, aukstesnioL2);
    }
    auto endlist2 = std::chrono::high_resolution_clock::now();
    chrono::duration<double> difflist2 = endlist2 - startlist2;
    cout << "Programos veikimo sparta naudojant ANTRĄ strategiją su list: " << difflist2.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;


//    VECTOR

    vector<Studentas> studentaiVector2;
    vector<Studentas> zemesniojoLygioVector2;

    cout << "VECTOR:" << endl;
    // istrynimui studento is vektoriaus, kai mazesnis nei 5 galutinis balas buvo panaudotas remove_if
    auto start2vec = std::chrono::high_resolution_clock::now();
    auto startas2vec = start2vec;
    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        VECTOR2AtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, namuDarbuSkaicius);
        VECTOR2NuskaitymasIsFailo(studentaiVector2, studentuSkaicius, namuDarbuSkaicius);
        VECTOR2SkirstymasIGrupes(studentaiVector2, zemesniojoLygioVector2);
        VECTOR2Spausdinimas(studentuSkaicius, studentaiVector2, zemesniojoLygioVector2);
    }
    auto end2vec = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff2vec = end2vec - start2vec;
    cout << "Programos veikimo sparta naudojant ANTRĄ strategiją su vector: " << diff2vec.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;

    return 0;
}

