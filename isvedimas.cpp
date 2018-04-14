#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <random>
#include <fstream>
#include <deque>
#include <algorithm>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"

using std::cout; using std::cin; using std::endl; using std::setw;
using std::size_t; using std::fixed; using std::setprecision;

void pasirinkimas(studentas &S){
    cout<<"Skaiciuojame galutini bala\n1 - Naudoti vidurki\n2 - Naudoti mediana"<<endl;
    int a;
    cin>>a;
    auto kintamieji=S.pazymiai.size()-1;

        if(a==1)
        {
            auto nDarSuma=0;
            for(int i=0; i<kintamieji; i++) nDarSuma+=S.pazymiai[i];

            S.galBalasVid=vidurkis(nDarSuma, kintamieji, S.egzaminas);
            cout<<fixed<<setprecision(2)<<S.galBalasVid;
        }

        else if(a==2)
        {
            S.galBalasMed=mediana (S.pazymiai, kintamieji, S.egzaminas);
            cout<<fixed<<setprecision(2)<<S.galBalasMed;
        }

}
