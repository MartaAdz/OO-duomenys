#include <iostream>
#include <vector>
#include "studentas.h"

using std::vector; using std::size_t;

void skirstymas(vector<studentas>& S, unsigned int stud_kiekis, vector<studentas>& geras, vector<studentas>& blogas){
    blogas.push_back(studentas());
    geras.push_back(studentas());
    for (size_t i=0; i<stud_kiekis; i++)
    {

            if (S[i].pazymiai[0]+S[i].pazymiai[1]+S[i].pazymiai[2]<18) ////10*3*60/100=18
            {
                blogas.push_back({S[i].vardas, S[i].pavarde, S[i].galBalasVid, S[i].galBalasMed});
            }
            else
            {
                geras.push_back({S[i].vardas, S[i].pavarde, S[i].galBalasVid, S[i].galBalasMed});
            }
    }
}
