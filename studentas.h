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

    studentas(): galBalas {0.0} {} //default kontuktorius
    studentas(std::istream& duomenys); //konstruktorius su nuskaitymu is failo

    inline std::string getVardas() const {return vardas;}
    inline std::string getPavarde() const {return pavarde;}
    inline double getBalas() const { return galBalas;}
    inline int getEgzaminas() const {return egzaminas;}
    friend std::ostream& operator<<(std::ostream& output, const studentas &s) {
        output << s.vardas<<" "<<s.pavarde<<" "<<s.galBalas<<" ";
        return output;
    }
    bool operator==(const studentas &s);
    bool operator!=(const studentas &s);
};


bool operator<(const studentas&rhs, const studentas&lhs);
bool operator>(const studentas&rhs, const studentas&lhs);

#endif
