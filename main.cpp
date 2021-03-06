#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <algorithm>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>
#include "studentas.h"
#include "funkcijos.h"


int main()
{
    std::cout<<"STUDENTU INFORMACIJA APDOROJANTI PROGRAMA"<<std::endl;

        unsigned int stud_kiekis;

        stud_kiekis = 10000;  
        const int paz_kiekis = 5;  
        
        studentu_generavimas(stud_kiekis, paz_kiekis);

        std::ifstream duomenys("kursiokai.txt");

        try{
            if(duomenys.fail())
            {
                throw std::exception();
            }
        }
        catch (std::exception &e1)
        {   e1.what();
            std::cerr<<"Tokio failo nera. Baigiu programa.";
            exit(1);
        }


        using namespace std::chrono;


        high_resolution_clock::time_point t_vec_1 = high_resolution_clock::now();

            std::vector<studentas> S;
            visi_toVec(duomenys, S, stud_kiekis);
            rikiavimas_vec(S);
            dvi_grupes(S);
            stud_toFile_vec(S);


            high_resolution_clock::time_point t_vec_2 = high_resolution_clock::now();
            duration<double> time = duration_cast<duration<double>>(t_vec_2 - t_vec_1);

            std::cout << stud_kiekis <<" uztruko " << time.count() << " sekundziu.\n";
            stud_kiekis*=10;


 return 0;
}
