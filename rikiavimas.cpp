#include <iostream>
#include <vector>
#include "studentas.h"

using std::size_t;

void rikiavimas(std::vector<studentas>&S){

    for(size_t c=1; c < S.size() ; c++)
    {
        while (S[c].pavarde < S[c - 1].pavarde)
        {
            std::swap(S[c], S[c - 1]);
            c--;
        }
    }
}
