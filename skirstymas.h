#ifndef rikiavimasimas_H
#define rikiavimas_H
#include "studentas.h"
#include <vector>
#include <deque>
#include <list>
    void skirstymas_vec(std::vector<studentas>& S, unsigned int stud_kiekis,
                    std::vector<studentas>& geras, std::vector<studentas>& blogas);
    std::vector<studentas> skirstymas_trinant_vec(std::vector<studentas>& S, std::vector<studentas>& blogas);
    void skirstymas_list(std::list<studentas>& stud_list, unsigned int stud_kiekis,
                          std::list<studentas>& geri, std::list<studentas>& blogi);
    std::list<studentas> skirstymas_trinant_list (std::list<studentas>& stud_list, std::list<studentas>& blogi);
    void skirstymas_dek(std::deque<studentas>& S, unsigned int stud_kiekis,
                        std::deque<studentas>& geri, std::deque<studentas>& blogi);
    std::deque<studentas> skirstymas_trinant_dek(std::deque<studentas>& stud_dek, std::deque<studentas>& blogi);

#endif
