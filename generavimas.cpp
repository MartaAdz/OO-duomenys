#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "vidurkis.h"
#include "mediana.h"
using std::cout; using std::endl; using std::vector; using std::string;

void random(unsigned int a){
        vector<int> nDarbas;
        std::ofstream  f("kursiokai.txt");
        for(int i=0; i<a; i++)
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

            f<<vidurkis(nDarSuma, 3, egzaminas)<<" "<<mediana (nDarbas, 3, egzaminas)<<" "<<egzaminas;

    }

}
