#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "vidurkis.h"
#include "mediana.h"
using std::cout; using std::endl; using std::vector; using std::string; using std::cin;

void studentu_generavimas(unsigned int studentu_kiekis){
        vector<int> nDarbas;
        std::ofstream  f("kursiokai.txt");
        for(int i=0; i<studentu_kiekis; i++)
        {
            f <<  "vardas" << std::to_string(i) <<" "<<"pavarde"<< std::to_string(i)<<" ";

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 10);

            nDarbas.push_back(int());
            for(int j=0; j<3; j++)
            {
                nDarbas[j]=dis(gen);
                f<<nDarbas[j]<<" ";
            }

            int egzaminas=dis(gen);

                    auto nDarSuma=0;
                    for(int i=0; i<3; i++) nDarSuma+=nDarbas[i];

            f<<egzaminas<<endl;

    }
}

void iverciai(studentas &S, int kiekis){

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(1, 10);

                vector<int> nDarbas;
                nDarbas.push_back(int());
                for(int i=0; i<kiekis; i++) nDarbas.push_back(dis(gen));
                S.pazymiai=nDarbas;

                S.egzaminas=dis(gen);

}
