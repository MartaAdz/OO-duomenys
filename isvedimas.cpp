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
void stud_toFile_vec(std::vector<studentas>& S){

    std::ofstream f("kursas.dat");
     f<<std::left<<setw(20)<<"Vardas"
                        <<setw(20)<<"Pavarde"
                        <<setw(20)<<"Galutinis-vidurkis"
                        <<setw(20)<<"Galutinis-mediana"
                        <<"\n";
      for(size_t c=0; c < S.size() ; c++)
        {
            f<<std::left<<setw(20)<<S[c].vardas
                        <<setw(20)<<S[c].pavarde
                        <<setw(20)<<fixed<<setprecision(2)<<S[c].galBalasVid
                        <<setw(20)<<fixed<<setprecision(2)<<S[c].galBalasMed<<endl;
        }
}
void stud_toFile_list(std::list<studentas>& stud_list){

    std::ofstream f("kursas.dat");
     f<<std::left<<setw(20)<<"Vardas"
                        <<setw(20)<<"Pavarde"
                        <<setw(20)<<"Galutinis-vidurkis"
                        <<setw(20)<<"Galutinis-mediana"
                        <<"\n";
      for (studentas einamas : stud_list) {

            f<<std::left<<setw(20)<<einamas.vardas
                        <<setw(20)<<einamas.pavarde
                        <<setw(20)<<fixed<<setprecision(2)<<einamas.galBalasVid
                        <<setw(20)<<fixed<<setprecision(2)<<einamas.galBalasMed<<endl;
        }
}
void stud_toFile_dek(std::deque<studentas>& stud_dek){

    std::ofstream f("kursas.dat");
     f<<std::left<<setw(20)<<"Vardas"
                        <<setw(20)<<"Pavarde"
                        <<setw(20)<<"Galutinis-vidurkis"
                        <<setw(20)<<"Galutinis-mediana"
                        <<"\n";
   for(size_t c=0; c < stud_dek.size() ; c++)
        {
            f<<std::left<<setw(20)<<stud_dek[c].vardas
                            <<setw(20)<<stud_dek[c].pavarde
                            <<setw(20)<<fixed<<setprecision(2)<<stud_dek[c].galBalasVid
                            <<setw(20)<<fixed<<setprecision(2)<<stud_dek[c].galBalasMed<<endl;
        }
}
