//
// Created by Jaune Malukaite on 2021-12-15.
//

#ifndef INC_2_0VERSIJA_STUDENTAS_H
#define INC_2_0VERSIJA_STUDENTAS_H

/** @brief class Studentas is used for functions that read information, calculate marks and others.
    Detailde description follows here.
    @author Jaune Malukaite
    @date December 2021
  */
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>
#include <chrono>
using namespace std;

/** Abstract class Zmogus */
class Zmogus {
protected:
    string vardas;
    string pavarde;
public:
    /** default constructor */
    Zmogus() {};
    /** default destructor */
    ~Zmogus() {};
    /** virtual functions */
    virtual string getVardas() const = 0;
    virtual string getPavarde() const = 0;
};

/** Derived class from class Zmogus */
class Studentas : public Zmogus {
private:
    vector<int> namuDarbai;
    int egzaminas;
public:
    /** constructor */
    Studentas() : egzaminas(0) {};
    Studentas(ifstream& fd, int namuDarbuSkaicius);
    string getVardas() const { return vardas;}
    string getPavarde() const { return pavarde;}

    int getEgzaminas() const;

    double getGalutinis();

    void setNamuDarbai(const vector<int> &namuDarbai);

    void setEgzaminas(int egzaminas);

    /** read information of a particular student
     * @param vardas - the name of a student
     * @param pavarde - the surname of a student
     * @param namuDarbai - homework marks
     * @param egzaminas - exam mark
     * @see readStudentas()
     * */
    void readStudentas(ifstream&, int);

};
#endif //INC_2_0VERSIJA_STUDENTAS_H
