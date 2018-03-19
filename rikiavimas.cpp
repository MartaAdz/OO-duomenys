#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "studentas.h"

using std::sort;

bool lyginimas (const studentas &rhs, const studentas &lhs) { return lhs.pavarde<rhs.pavarde; }
void rikiavimas_vec(std::vector<studentas>&S){
    sort(S.begin(), S.end(), lyginimas);
}
void rikiavimas_list(std::list<studentas>&stud_list){
    stud_list.sort(lyginimas);
}
