#ifndef isvedimas_H
#define isvedimas_H
#include "studentas.h"
#include <fstream>
#include <vector>

    void studentu_generavimas(unsigned int studentu_kiekis, int paz_kiekis);
    void visi_toVec(std::istream &duomenys, std::vector<studentas> &S, unsigned int stud_kiekis);
    void rikiavimas_vec(std::vector<studentas> &S);
    std::vector<studentas> dvi_grupes(std::vector<studentas>&S);
    void stud_toFile_vec(std::vector<studentas>& S);
#endif
