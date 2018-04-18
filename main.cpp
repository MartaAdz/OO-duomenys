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
        std::cout<<"Generuojamu studentu kiekis: ";
        std::cin>>stud_kiekis;

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
            std::cout<<"Tokio failo nera. Baigiu programa.";
            exit(1);
        }


        using namespace std::chrono;
        high_resolution_clock::time_point t_vec_1 = high_resolution_clock::now();

            std::vector<studentas> S;
            visi_toVec(duomenys, S, stud_kiekis);
            rikiavimas_vec(S);

            std::vector<studentas> blogi;
            skirstymas(S, blogi);
            stud_toFile_vec(S);


            high_resolution_clock::time_point t_vec_2 = high_resolution_clock::now();
            duration<double> time = duration_cast<duration<double>>(t_vec_2 - t_vec_1);

            std::cout<<"Faile issaugoti pazangus studentai.\n";

            std::cout << "Uztruko " << time.count() << " sekundziu.";



 return 0;
}
