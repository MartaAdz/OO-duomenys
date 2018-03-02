#include <iostream>
#include <iomanip>
#include <vector>
#include "studentas.h"
#include "vidurkis.h"

using std::cout; using std::endl; using std::setw;

double vidurkis(int a, int b, int c){
    double galBalas=0.4*(a/b)+0.6*c;
    //cout.precision (3);
    //cout<<"Galutinis balas: "<<galBalas;
    return galBalas;
}

double vidurkis(studentas &S){

    auto kintamieji=S.pazymiai.size()-1;
    auto nDarSuma=0;
    for(int i=0; i<kintamieji; i++) nDarSuma+=S.pazymiai[i];
    double galBalas=0.4 * (nDarSuma/kintamieji)+0.6 * S.egzaminas;
    //cout.precision (3);
    //cout<<setw(20)<<galBalas;
    return galBalas;
}
