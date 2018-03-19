#ifndef nuskaitymas_H
#define nuskaitymas_H
#include "studentas.h"
#include <list>
    void nuskaitymas_vec(std::vector<studentas>& S, unsigned int stud_kiekis, std::ifstream &duomenys);
    void nuskaitymas_list(std::list<studentas>& stud_list, std::ifstream &duomenys);
#endif
