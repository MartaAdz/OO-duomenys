#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"
#include "generavimas.h"
#include "isvedimas.h"
#include "nuskaitymas.h"
#include "rikiavimas.h"

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;
using std::setw; using std::swap;
int main()
{
    cout<<"1-nuskaityti is failo, 2-ivesti ranka. \n";

    int p;
    cin>>p;

    if(p==1){
        unsigned int stud_kiekis;
        cout<<"kiek studentu sugeneruoti: ";
        cin>>stud_kiekis;
        studentu_generavimas(stud_kiekis);
        std::ifstream duomenys("kursiokai.txt");

        try{
            if(duomenys.fail())
            {
                throw std::exception();
            }
        }
        catch (std::exception &e1)
        {   e1.what();
            cout<<"Tokio failo nera. Baigiu programa.";
            exit(1);
        }
        vector<studentas> S;
        nuskaitymas (S, stud_kiekis, duomenys);
        cout<<std::left<<setw(20)<<"Vardas"
                        <<setw(20)<<"Pavarde"
                        <<setw(20)<<"Galutinis-vidurkis"
                        <<setw(20)<<"Galutinis-mediana"
                        <<"\n";


        rikiavimas(S);
        stud_isvedimas(S);


    }
    else if(p==2) {
        auto d=1;
        auto i=0;
        vector<studentas> S;
        S.push_back(studentas());
        while(d!=2){

            cout<<"Iveskite studento varda ir pavarde: ";
            string var, pav;
            cin>>var;
            S[i].vardas=var;
            cin>>pav;
            S[i].pavarde=pav;

            cout<<"1-generuoti pazymius, 2-ivesti pazymius: ";
            int p;
            cin>>p;


            if(p==1){

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(1, 10);

                cout<<"Kiek pazymiu norite sugeneruoti?";
                int kiekis;
                cin>>kiekis;

                iverciai (S[i],kiekis);
                for(int j=1;j<kiekis;j++) cout<<S[i].pazymiai[j]; //isveda pazymius

                cout<<endl;

                pasirinkimas(S[i]);

            }
             else if (p==2)
            {
                cout<<"Iveskite pazymius. (Pabaigus ivesti -1)"<<endl;
                int pazymys;
                for(int j=0; i<S[i].pazymiai.size()+1; j++)
                {
                    cout<<j+1<<" pazymys: ";
                    cin>>pazymys;
                    S[i].pazymiai.push_back(pazymys);

                    if (pazymys==-1) break;
                }

                cout<<endl;
                cout<<"Iveskite egzamino pazymi: ";
                int egzaminas;
                cin>>egzaminas;
                S[i].egzaminas=egzaminas;

                cout<<endl;
                pasirinkimas(S[i]);
            }
        i++;
        S.push_back(studentas());
        cout<<"\n1 - testi duomenu ivedima, 2 - baigti duomenu ivedima: ";
        cin>>d;
    }
}

 return 0;
}
