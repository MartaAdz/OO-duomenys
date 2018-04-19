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

    studentas(): galBalas {0} {}
    studentas(std::istream& duomenys);
    inline std::string getVardas() const {return vardas;}
    std::string getPavarde() const {return pavarde;}
    std::vector<int> getPazymiai() const {return pazymiai;}
    int getEgzaminas() const {return egzaminas;}
    double getBalas() const { return galBalas;}




    void setGalutinis(std::vector<int> &pazymiai, int &egzaminas);

    bool arGeras();
    bool arBlogas();
};

bool lyginimas_egzaminas(const studentas &rhs, const studentas &lhs);

#endif
