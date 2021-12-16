#include "studentas.h"

Studentas::Studentas(ifstream& fd, int namuDarbuSkaicius)
{
    readStudentas(fd, namuDarbuSkaicius);
}

double Studentas::getGalutinis() {
    /** calculates the final mark by accumulating homework marks and adding exam mark */
    double galutinis = 0.4 * (accumulate(this->namuDarbai.begin(), this->namuDarbai.end(), 0.0)
            / this->namuDarbai.size()) + 0.6 * this -> egzaminas;
    return galutinis;
}

void Studentas::readStudentas(ifstream &fd, int namuDarbuSkaicius) {
    /** reads information about one student */
    fd >> this->vardas >> this->pavarde;
    this->namuDarbai.reserve(namuDarbuSkaicius);
    for (int i = 0; i < namuDarbuSkaicius; i++)
    {
        int ivestis;
        fd >> ivestis;
        this->namuDarbai.push_back(ivestis);
    }
    fd >> this-> egzaminas;
}

void Studentas::setNamuDarbai(const vector<int> &namuDarbai) {
    Studentas::namuDarbai = namuDarbai;
}

void Studentas::setEgzaminas(int egzaminas) {
    Studentas::egzaminas = egzaminas;
}

int Studentas::getEgzaminas() const {
    return egzaminas;
}
