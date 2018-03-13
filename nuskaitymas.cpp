#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "studentas.h"
#include "generavimas.h"

using std::vector; using std::string;

void nuskaitymas(vector<studentas>& S, unsigned int stud_kiekis, std::ifstream &duomenys){

 //   vector<studentas> S;
    string var, pav;
    vector <int> paz (3,0);
    int egz;
    auto i=0;

    while(!duomenys.eof())
    {
        duomenys >> var >> pav >> paz[0] >> paz[1] >> paz[2] >> egz;
        S.push_back(studentas());
        S[i].vardas=var;
        S[i].pavarde=pav;
        S[i].pazymiai.push_back(paz[0]);
        S[i].pazymiai.push_back(paz[1]);
        S[i].pazymiai.push_back(paz[2]);
        S[i].egzaminas=egz;
        i++;
        if (i==stud_kiekis) break;
    }
 }
