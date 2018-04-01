#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <fstream>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"
#include "generavimas.h"

using std::vector; using std::string;

void nuskaitymas_vec(vector<studentas>& S, std::ifstream &duomenys, int paz_kiekis){
    string var, pav;
    vector <int> paz (paz_kiekis, 0);
    int egz;

    while(!duomenys.eof())
    {
        duomenys >> var >> pav;
        for(int i=0; i<paz_kiekis; i++) duomenys>> paz[i];
        duomenys >> egz;
        studentas stud;
        stud.vardas=var;
        stud.pavarde=pav;
        for (auto i=0; i!=paz_kiekis; i++) stud.pazymiai.push_back(paz[i]);
        stud.egzaminas=egz;
        stud.galBalasVid=vidurkis(stud);
        stud.galBalasMed=mediana(stud);

        S.push_back(stud);
    }
 }
void nuskaitymas_list(std::list<studentas>& stud_list, std::ifstream &duomenys, int paz_kiekis){
    string var, pav;
    vector <int> paz (paz_kiekis, 0);
    int egz;

    while(!duomenys.eof())
    {
        duomenys >> var >> pav;
        for(int i=0; i<paz_kiekis; i++) duomenys>> paz[i];
        duomenys >> egz;
        studentas stud;
        stud.vardas=var;
        stud.pavarde=pav;
        for (auto i=0; i!=paz_kiekis; i++) stud.pazymiai.push_back(paz[i]);
        stud.egzaminas=egz;
        stud.galBalasVid=vidurkis(stud);
        stud.galBalasMed=mediana(stud);
        stud_list.push_back(stud);
    }
 }
void nuskaitymas_dek(std::deque<studentas>& stud_dek, std::ifstream &duomenys, int paz_kiekis){
    string var, pav;
    vector <int> paz (paz_kiekis, 0);
    int egz;

    while(!duomenys.eof())
    {
        duomenys >> var >> pav;
        for(int i=0; i<paz_kiekis; i++) duomenys>> paz[i];
        duomenys >> egz;
        studentas stud;
        stud.vardas=var;
        stud.pavarde=pav;
        for (auto i=0; i!=paz_kiekis; i++) stud.pazymiai.push_back(paz[i]);
        stud.egzaminas=egz;
        stud.galBalasVid=vidurkis(stud);
        stud.galBalasMed=mediana(stud);

        stud_dek.push_back(stud);
    }

 }
