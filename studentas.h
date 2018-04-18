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
public:
    std::string vardas;
    std::string pavarde;
    std::vector <int> pazymiai;
    int egzaminas;
    double galBalas;

public:

    studentas(): galBalas {0} {}

    std::string getVardas() const {return vardas;}
    std::string getPavarde() const {return pavarde;}
    std::vector<int> getPazymiai() const {return pazymiai;}
    int getEgzaminas() const {return egzaminas;}
    double getBalas() const { return galBalas;}


    void stud_fromFile(std::istream &duomenys){

        int paz;
        int paz_kiekis = 5;

        duomenys >> vardas >> pavarde;

        for (size_t i=0; i!=paz_kiekis; i++){

            duomenys>>paz;
            pazymiai.push_back(paz);
        }
        duomenys>>egzaminas;
    }

    void setGalutinis(std::vector<int> &pazymiai, int &egzaminas){

        auto nDarSuma=0;
        for(int i=0; i<pazymiai.size()-1; i++) nDarSuma+=pazymiai[i];
        galBalas = 0.4 * (nDarSuma/pazymiai.size()-1)+0.6 * egzaminas;

    }


};

#endif
