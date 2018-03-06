#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"
using std::cout; using std::endl; using std::vector; using std::string;

void random(){
        vector<studentas> S;
        vector<int> nDarbas(3,0);
        int pazymys;
        std::ofstream  f("failas.dat");
        for(int i=0; i<=100; i++)
        {
            S.push_back(studentas());

            string var = "vardas" + std::to_string(i);
            string pav = "pavarde" + std::to_string(i);
            S[i].vardas=var;
            S[i].pavarde=pav;
            f  << S[i].vardas<<" "<<S[i].pavarde<<" ";

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 10);

            for(int j=0; j<3; j++)
            {
                pazymys=dis(gen);
                cout<<pazymys<<" ";
                nDarbas.push_back(pazymys);
                f<<pazymys<<" ";

            }

            S[i].pazymiai=nDarbas;
            int egzaminas=dis(gen);
            cout<<"\nEgzamino pazymys: "<<egzaminas;
            S[i].egzaminas=egzaminas;

                    auto nDarSuma=0;
                    for(int i=0; i<3; i++) nDarSuma+=nDarbas[i];

            S[i].galBalasVid=vidurkis(nDarSuma, 3, egzaminas);
            S[i].galBalasMed=mediana (nDarbas, 3, egzaminas);

            f << S[i].galBalasMed<<" "<< S[i].galBalasVid<<" "<<S[i].egzaminas<<"\n";

            S.push_back(studentas());
            cout<<"\n";
    }

}
