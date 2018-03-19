#ifndef nuskaitymas_H
#define nuskaitymas_H
#include "studentas.h"
#include <list>
#include <vector>
#include <deque>
    void nuskaitymas_vec(std::vector<studentas>& S, std::ifstream &duomenys);
    void nuskaitymas_list(std::list<studentas>& stud_list, std::ifstream &duomenys);
    void nuskaitymas_dek(std::deque<studentas>& stud_dek, std::ifstream &duomenys);
#endif
