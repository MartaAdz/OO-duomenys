#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>
#include "studentas.h"

void studentu_generavimas(unsigned int studentu_kiekis, int paz_kiekis){
        std::vector<int> nDarbas;
        std::ofstream  f("kursiokai.txt");
        for(int i=0; i<studentu_kiekis; i++)
        {
            f <<  "vardas" << std::to_string(i) <<" "<<"pavarde"<< std::to_string(i)<<" ";

            using namespace std::chrono;
            std::random_device rseed;
            std::mt19937 gen(rseed()*1000*static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().
            time_since_epoch().count()));
            std::uniform_int_distribution<int> dst(1,10);

            int paz;
            for(size_t i=0; i!=paz_kiekis; i++)
            {
                paz=dst(gen);
                nDarbas.push_back(paz);
                f<<nDarbas[i]<<" ";
            }

            int egzaminas=dst(gen);
            f<<egzaminas<<std::endl;

        }
}

void visi_toVec(std::istream &duomenys, std::vector<studentas> &S, unsigned int stud_kiekis){

    for (size_t i=0; i<stud_kiekis; i++){
        studentas s (duomenys);
        S.push_back(s);
    }

}

void rikiavimas_vec(std::vector<studentas>&S){ sort(S.begin(), S.end(), lyginimas_egzaminas); }

bool arGeras(const studentas &s) {if (s.getBalas()>=5) return true;}
bool arBlogas(const studentas &s) { if (s.getBalas()<5) return true;}

void skirstymas(std::vector<studentas>& S, std::vector<studentas>& blogi){

    std::remove_copy_if(S.begin(), S.end(), std::back_inserter(blogi), arGeras);
    S.erase(remove_if(S.begin(), S.end(), arBlogas), S.end());
}

void stud_toFile_vec(std::vector<studentas>& S){

    std::ofstream f("gerieji.dat");

    f<<"PAZANGUS STUDENTAI\n"
                        <<std::left<<std::setw(20)<<"Vardas"
                        <<std::setw(20)<<"Pavarde"
                        <<std::setw(20)<<"Galutinis-vidurkis"
                        <<"\n";

    for(auto it = S.begin(); it != S.end() ; it++)
        {
            f<<std::left<<std::setw(20)<<(*it).getVardas()
                        <<std::setw(20)<<(*it).getPavarde()
                        <<std::setw(20)<<std::fixed<<std::setprecision(2)<<(*it).getBalas()<<std::endl;
        }
}
