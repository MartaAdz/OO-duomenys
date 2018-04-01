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
            std::mt19937 gen(rseed()*static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().
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
void iverciai(studentas &S, int kiekis){

                using namespace std::chrono;
                std::random_device rseed;
                std::mt19937 gen(rseed()*static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().
                time_since_epoch().count()));
                std::uniform_int_distribution<int> dst(1,10);

                vector<int> nDarbas;
                int ivertis;
                for(int i=0; i<kiekis; i++)
                {
                    ivertis=dst(gen);
                    nDarbas.push_back(ivertis);
                }
                S.pazymiai=nDarbas;

                S.egzaminas=dst(gen);

}
vector<int> ivesti_pazymiai(studentas &stud){

                cout<<"Iveskite pazymius. (Pabaigus ivesti -1)"<<endl;
                int pazymys;
                for(int j=0; j<stud.pazymiai.size()+1; j++)
                {
                    if ( !(cin >> pazymys) )
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Klaidingas iveimas. Bandykite dar karta: ";
                    }

                    stud.pazymiai.push_back(pazymys);

                    if (pazymys==-1) break;
                }

            return stud.pazymiai;

}
