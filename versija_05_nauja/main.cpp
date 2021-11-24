#include "libraries.h"
#include "realizacija_su_list.h"
#include "realizacija_su_vektoriais.h"

int main() {

    int namuDarbuSkaicius = 4;
    string pavadinimas;
    int studentuSkaiciai[5] = {1000, 10000, 100000, 1000000, 10000000};

    list<Studentas> studentaiLIST;
    list<Studentas> aukstesniojoLygioLIST;
    list<Studentas> zemesniojoLygioLIST;

    vector<Studentas> studentaiVECTOR;
    vector<Studentas> aukstesniojoLygioVECTOR;
    vector<Studentas> zemesniojoLygioVECTOR;

    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        cout << to_string(studentuSkaicius) << " studentų" << endl;
        NuskaitymasIsFailoLIST(studentaiLIST, studentuSkaicius, namuDarbuSkaicius);
        NuskaitymasIsFailoVECTOR(studentaiVECTOR, studentuSkaicius, namuDarbuSkaicius);
        SkirstymasIGrupesLIST(studentaiLIST, aukstesniojoLygioLIST, zemesniojoLygioLIST);
        SkirstymasIGrupesVECTOR(studentaiVECTOR, aukstesniojoLygioVECTOR, zemesniojoLygioVECTOR);
        SpausdinimasLIST(studentuSkaicius, aukstesniojoLygioLIST, zemesniojoLygioLIST);
        SpausdinimasVECTOR(studentuSkaicius, aukstesniojoLygioVECTOR, zemesniojoLygioVECTOR);
        studentaiLIST.clear();
        aukstesniojoLygioLIST.clear();
        zemesniojoLygioLIST.clear();
        studentaiVECTOR.clear();
        aukstesniojoLygioVECTOR.clear();
        zemesniojoLygioVECTOR.clear();
    }


    return 0;
}

