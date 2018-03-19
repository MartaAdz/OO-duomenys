#ifndef isvedimas_H
#define isvedimas_H
#include "studentas.h"
#include <list>
#include <vector>
#include <deque>
    void pasirinkimas(studentas &S);
    void stud_toFile_vec(std::vector<studentas>& S);
    void stud_toFile_list(std::list<studentas>& stud_list);
    void stud_toFile_dek(std::deque<studentas>& stud_dek);
#endif
