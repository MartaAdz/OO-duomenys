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

void nuskaitymas_vec(vector<studentas>& S, std::ifstream &duomenys){
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

        S.push_back(stud);
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

 void nuskaitymas_dek(std::deque<studentas>& stud_dek, std::ifstream &duomenys){
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

        stud_dek.push_back(stud);
    }
 }
