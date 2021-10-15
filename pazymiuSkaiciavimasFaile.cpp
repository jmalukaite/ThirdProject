#include "studentas.h"

double PazymiuSkaiciavimasFaile(std::string const &stream) {
    std::stringstream streaming(stream);
    // Grąžina 'atstumą' tarp pirmo ir paskutinio elemento nuskaitytoje eilutėje,
    // atimame 3, kad rastume pažymių skaičių (atimame 3 elementus - vardą, pavardę bei egzaminoRezultatą)
    return distance(std::istream_iterator<std::string>(streaming), std::istream_iterator<std::string>()) - 3;
}
