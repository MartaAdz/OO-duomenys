#ifndef rikiavimasimas_H
#define rikiavimas_H
#include "studentas.h"
#include <vector>
#include <deque>
#include <list>
    void skirstymas_vec(std::vector<studentas>& S, unsigned int stud_kiekis,
                    std::vector<studentas>& geras, std::vector<studentas>& blogas);
    void skirstymas_list(std::list<studentas>& stud_list, unsigned int stud_kiekis);
    void skirstymas_dek(std::deque<studentas>& S, unsigned int stud_kiekis,
                        std::deque<studentas>& geri, std::deque<studentas>& blogi);
#endif
