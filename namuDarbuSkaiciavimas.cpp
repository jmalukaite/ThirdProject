#include "studentas.h"

double NamuDarbuMedianosSkaiciavimas(Studentas studentas) {
    double mediana;
    sort(studentas.namuDarbai.begin(), studentas.namuDarbai.end());
    int vidurinisElementas = studentas.namuDarbai.size() / 2;
    if (studentas.namuDarbai.size() / 2 == 0) {
        mediana = (studentas.namuDarbai[vidurinisElementas - 1] + studentas.namuDarbai[vidurinisElementas]) / 2.;
    } else {
        mediana = studentas.namuDarbai[vidurinisElementas];
    }
    return mediana;
}

double NamuDarbuVidurkioSkaiciavimas(Studentas studentas) {
    double vidurkis =
            accumulate(studentas.namuDarbai.begin(), studentas.namuDarbai.end(), 0.0) / studentas.namuDarbai.size();
    if (studentas.namuDarbai.size() == 0)
    {
        throw "Studentas turėjo atlikti bent vieną namų darbą!";
    }
    return vidurkis;
}