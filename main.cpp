#include "studentas.h"
#include "duomenuIvedimasIrSaugojimas.h"

int main() {
    int studentuSkaicius = 0;
    std::vector<Studentas> studentai;
    studentai.reserve(10000);
    DuomenuIvedimasIrSaugojimas(studentai, studentuSkaicius);
    return 0;
}








