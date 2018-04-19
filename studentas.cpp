#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <vector>
#include <fstream>
#include <algorithm>
#include "studentas.h"
void studentas::stud_fromFile(std::istream &duomenys){

        int paz;
        int paz_kiekis = 5;

        duomenys >> vardas >> pavarde;

        for (size_t i=0; i!=paz_kiekis; i++){

            duomenys>>paz;
            pazymiai.push_back(paz);
        }
        duomenys>>egzaminas;

        auto nDarSuma=0;
        for(int i=0; i<pazymiai.size()-1; i++) nDarSuma+=pazymiai[i];

        galBalas = 0.4 * (nDarSuma/pazymiai.size()-1)+0.6 * egzaminas;

    }

studentas::studentas(std::istream&duomenys){
    stud_fromFile(duomenys);
}
//bool studentas::arGeras() {
//    if (galBalas>=5) return true;
//}
//
//bool studentas::arBlogas() {
//    if (galBalas<5) return true;
//}

bool lyginimas_egzaminas(const studentas &rhs, const studentas &lhs){ return lhs.getEgzaminas()>rhs.getEgzaminas();}


