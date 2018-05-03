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

bool studentas::operator==(const studentas&s){
    return (vardas==s.getVardas()&&pavarde==s.getPavarde()&& galBalas==s.getBalas());
}
bool studentas::operator!=(const studentas&s){
    return !operator==(s);
}
bool operator<(const studentas&rhs, const studentas&lhs){
        return (rhs.getBalas()<lhs.getBalas());
}
bool operator>(const studentas&rhs, const studentas&lhs){
        return (rhs.getBalas()>lhs.getBalas());
}


//bool operator!=(const studentas&rhs, const studentas&lhs){
//    return (rhs.getVardas()!=lhs.getVardas()&&rhs.getPavarde()!=lhs.getPavarde()&&rhs.getBalas()!=lhs.getBalas());
//}

//bool dvi_grupes(const studentas &rhs, const studentas &lhs){}
bool lyginimas_egzaminas(const studentas &rhs, const studentas &lhs){ return lhs.getEgzaminas()>rhs.getEgzaminas();}


