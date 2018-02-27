#include <iostream>
#include <iomanip>
#include <vector>
#include "studentas.h"

using std::cout; using std::endl; using std::setw;

void vidurkis(struct studentas &S){

    auto kintamieji=S.pazymiai.size()-1;
    auto nDarSuma=0;
    for(int i=0; i<kintamieji; i++) nDarSuma+=S.pazymiai[i];
    double galBalas=0.4 * (nDarSuma/kintamieji)+0.6 * S.egzaminas;
    cout.precision (3);
    cout<<setw(20)<<galBalas;

}
