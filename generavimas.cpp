#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include <ctime>
#include <ratio>
#include <chrono>
#include "vidurkis.h"
#include "mediana.h"
using std::cout; using std::endl; using std::vector; using std::string; using std::cin;

void studentu_generavimas(unsigned int studentu_kiekis){
        vector<int> nDarbas;
        std::ofstream  f("kursiokai.txt");
        for(int i=0; i<studentu_kiekis; i++)
        {
            f <<  "vardas" << std::to_string(i) <<" "<<"pavarde"<< std::to_string(i)<<" ";

            using namespace std::chrono;
            std::random_device rseed;
            std::mt19937 gen(rseed()*static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().
            time_since_epoch().count()));
            std::uniform_int_distribution<int> dst(1,10);

            for(int i=0; i!=3; i++)
            {
                nDarbas.push_back(dst(gen));
                f<<nDarbas[i]<<" ";
            }

            int egzaminas=dst(gen);
            f<<egzaminas<<endl;

    }
}
void iverciai(studentas &S, int kiekis){

                using namespace std::chrono;
                std::random_device rseed;
                std::mt19937 gen(rseed()*static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().
                time_since_epoch().count()));
                std::uniform_int_distribution<int> dst(1,10);

                vector<int> nDarbas;
                nDarbas.push_back(int());
                for(int i=0; i<kiekis; i++) nDarbas.push_back(dst(gen));
                S.pazymiai=nDarbas;

                S.egzaminas=dst(gen);

}
