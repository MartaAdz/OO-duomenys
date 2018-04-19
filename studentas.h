#ifndef _STUDENTAS_H
#define _STUDENTAS_H
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <vector>
#include <fstream>
#include <algorithm>

class studentas{
private:
    std::string vardas;
    std::string pavarde;
    std::vector <int> pazymiai;
    int egzaminas;
    double galBalas;
    void stud_fromFile(std::istream &duomenys);

public:

    studentas(): galBalas {0} {} //default kontuktorius
    studentas(std::istream& duomenys); //konstruktorius su nuskaitymu is failo

    inline std::string getVardas() const {return vardas;}
    inline std::string getPavarde() const {return pavarde;}
    inline double getBalas() const { return galBalas;}
    inline int getEgzaminas() const {return egzaminas;}

//    bool arGeras();
//    bool arBlogas();
};

bool lyginimas_egzaminas(const studentas &rhs, const studentas &lhs);

#endif
