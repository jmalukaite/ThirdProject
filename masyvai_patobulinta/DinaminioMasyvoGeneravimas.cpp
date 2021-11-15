#include "libraries.h"


Studentas* DinaminioMasyvoGeneravimas(Studentas* studentai, int dydis)
{
    int naujasDydis = dydis * 2;
    Studentas* studentaiNaujas = new Studentas[naujasDydis];
    for (int i = 0; i < dydis; i++)
    {
        studentaiNaujas[i] = studentai[i];
    }
    for (int i = 0; i < dydis; i++)
    {
        studentaiNaujas[dydis + 1] = studentai[i];
    }
    delete [] studentai;
    return studentaiNaujas;
}

int* NamuDarbuMasyvoGeneravimas(int* namuDarbai, int dydis)
{
    int naujasDydis = dydis * 2;
    int* namuDarbaiNaujas = new int[naujasDydis];
    for (int i = 0; i < dydis; i++)
    {
        namuDarbaiNaujas[i] = namuDarbai[i];
    }
    for (int i = 0; i < dydis; i++)
    {
        namuDarbaiNaujas[dydis + 1] = namuDarbai[i];
    }
    delete [] namuDarbai;
    return namuDarbaiNaujas;
}