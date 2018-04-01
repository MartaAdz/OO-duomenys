#include <iostream>
#include <iomanip>
#include <vector>
#include "studentas.h"
#include "vidurkis.h"

using std::cout; using std::endl; using std::setw;
double vidurkis(int NDsuma, int kiekis, int egzas){
    double galBalas=0.4*(NDsuma/kiekis)+0.6*egzas;
    return galBalas;

}

double vidurkis(studentas &S){

    auto kintamieji=S.pazymiai.size()-1;
    auto nDarSuma=0;
    for(int i=0; i<kintamieji; i++) nDarSuma+=S.pazymiai[i];
    double galBalas=0.4 * (nDarSuma/kintamieji)+0.6 * S.egzaminas;
    return galBalas;

}
