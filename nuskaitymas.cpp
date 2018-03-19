#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <fstream>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"
#include "generavimas.h"

using std::vector; using std::string;

void nuskaitymas_vec(vector<studentas>& S, unsigned int stud_kiekis, std::ifstream &duomenys){
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
        S[i].galBalasVid=vidurkis(S[i]);
        S[i].galBalasMed=mediana(S[i]);
        i++;
        if (i==stud_kiekis) break;
    }
 }
void nuskaitymas_list(std::list<studentas>& stud_list, std::ifstream &duomenys){
    string var, pav;
    vector <int> paz (3,0);
    int egz;
    auto i=0;

    while(!duomenys.eof())
    {
        duomenys >> var >> pav >> paz[0] >> paz[1] >> paz[2] >> egz;
        studentas stud;
        stud.vardas=var;
        stud.pavarde=pav;
        stud.pazymiai.push_back(paz[0]);
        stud.pazymiai.push_back(paz[1]);
        stud.pazymiai.push_back(paz[2]);
        stud.egzaminas=egz;
        stud.galBalasVid=vidurkis(stud);
        stud.galBalasMed=mediana(stud);
        stud_list.push_back(stud);
    }
 }
