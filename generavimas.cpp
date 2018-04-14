#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <ctime>
#include <ratio>
#include <chrono>
#include "vidurkis.h"
#include "mediana.h"
#include "studentas.h"

using std::cout; using std::endl; using std::vector; using std::string; using std::cin;

void studentu_generavimas(unsigned int studentu_kiekis, int paz_kiekis){
        vector<int> nDarbas;
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
            for(int i=0; i!=paz_kiekis; i++)
            {
                paz=dst(gen);
                nDarbas.push_back(paz);
                f<<nDarbas[i]<<" ";
            }

            int egzaminas=dst(gen);
            f<<egzaminas<<endl;

    }
}
