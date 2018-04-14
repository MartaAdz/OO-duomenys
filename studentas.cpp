#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "studentas.h"

    double studentas::vidurkis(){
            auto kintamieji=pazymiai.size()-1;
            auto nDarSuma=0;
            for(int i=0; i<kintamieji; i++) nDarSuma+=pazymiai[i];
            double galBalas=0.4 * (nDarSuma/kintamieji)+0.6 * egzaminas;
            return galBalas;
        }

    double studentas::mediana(){
            int j;
            auto kiek=pazymiai.size()-1;
            for (int i = 1; i < kiek; i++)
            {
                j = i;
                while (j > 0 && pazymiai[j] < pazymiai[j - 1])
                {
                    std::swap(pazymiai[j], pazymiai[j - 1]); //rikiuojame pazymius
                    j--;
                }
            }

            if (j%2==0)
            {
                auto galBalas=0.4*pazymiai[j / 2]+0.6*egzaminas;
                return galBalas;
            }
            else
            {
                auto galBalas=0.4*(pazymiai[j / 2] + pazymiai[j / 2 +1])/2+0.6*egzaminas;
                return galBalas;
            }
        }

    void studentas::nuskaitymas(vector<student>& S, std::ifstream &duomenys, int paz_kiekis){

        string var, pav;
        vector <int> paz (paz_kiekis, 0);
        int egz;

        while(!duomenys.eof())
        {
            duomenys >> var >> pav;
            for(int i=0; i<paz_kiekis; i++) duomenys>> paz[i];
            duomenys >> egz;
            studentas stud;
            stud.vardas=var;
            stud.pavarde=pav;
            for (auto i=0; i!=paz_kiekis; i++) stud.pazymiai.push_back(paz[i]);
            stud.egzaminas=egz;

            S.push_back(stud);
        }
    }

   vector<studentas> studentas::skirstymas_trinant(std::vector<studentas>& S, std::vector<studentas>& blogi){

        std::remove_copy_if(S.begin(), S.end(), std::back_inserter(blogi), arGeras);
        S.erase(remove_if(S.begin(), S.end(), arBlogas), S.end());
        return blogi;
    }


    void studentas::stud_toFile(std::vector<studentas>& S){

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

