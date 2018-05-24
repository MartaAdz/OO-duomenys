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
    std::vector <int> pazymiai;  /*!< uz namu darbus gauti pazymiai */
    int egzaminas;
    double galBalas;  /*!< Galutinis balas, suskaiciuotas is pazymiu ir egzamino vidurkio */
    void stud_fromFile(std::istream &duomenys);  /*!< studentu nuskaitymas is failo */

public:

    studentas(): galBalas {0.0} {}  /*!< Default konstruktorius */
    studentas(std::istream& duomenys); /*!< konstruktorius su nuskaitymu is failo */
    //! varda grazinanti funkcija
    inline std::string getVardas() const {return vardas;}
    //! pavarde grazinanti funkcija
    inline std::string getPavarde() const {return pavarde;}
    //! galutini bala grazinanti funkcija
    inline double getBalas() const { return galBalas;}
    //! egzamino bala grazinanti funkcija
    inline int getEgzaminas() const {return egzaminas;}
    /**
    * Studento isvedimas i faila. Isvedamas vardas, pavarde ir galutinis balas.
    */ 
    friend std::ostream& operator<<(std::ostream& output, const studentas &s) {
        output << s.vardas<<" "<<s.pavarde<<" "<<s.galBalas<<" ";
        return output;
    }
    //! Prilyginimo operatorius
    /**
    * Prilyginamas vardas, pavarde, galutinis balas
    */ 
    bool operator==(const studentas &s);
    //! Operatorius nelygu
    /**
    * Grazinamas s jei == operatorius nera tiesa
    */ 
    bool operator!=(const studentas &s);
};


bool operator<(const studentas&rhs, const studentas&lhs);
bool operator>(const studentas&rhs, const studentas&lhs);

#endif
