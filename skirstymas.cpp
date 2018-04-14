#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include "studentas.h"

std::vector<studentas> skirstymas_trinant(std::vector<studentas>& S, std::vector<studentas>& blogi){

    std::remove_copy_if(S.begin(), S.end(), std::back_inserter(blogi), arGeras);
    S.erase(remove_if(S.begin(), S.end(), arBlogas), S.end());
    return blogi;
}

