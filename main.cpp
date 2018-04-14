#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <algorithm>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include "studentas.h"
//#include "vidurkis.h"
//#include "mediana.h"
//#include "generavimas.h"
//#include "isvedimas.h"
//#include "nuskaitymas.h"
//#include "rikiavimas.h"
//#include "skirstymas.h"

using std::cout; using std::cin; using std::endl; using std::string; using std::vector; using std::list; using std::deque;
int main()
{
    cout<<"STUDENTU INFORMACIJA APDOROJANTI PROGRAMA"<<endl;

        unsigned int stud_kiekis;
        cout<<"Generuojamu studentu kiekis: ";
        cin>>stud_kiekis;

        studentas S;

        const int paz_kiekis = 5;

        //studentu_generavimas(stud_kiekis, paz_kiekis);

        std::ifstream duomenys("kursiokai.txt");

        try{
            if(duomenys.fail())
            {
                throw std::exception();
            }
        }
        catch (std::exception &e1)
        {   e1.what();
            cout<<"Tokio failo nera. Baigiu programa.";
            exit(1);
        }

//            vector<studentas> S;
//            nuskaitymas_vec (S, duomenys, paz_kiekis);
//            rikiavimas_vec(S);
//
//            cout<<"1 - Skirstyti trinant is bendro konteinerio\n2 - Skirstyti perkeliant i du atskirus konteinerius\n";
//            int skirstymas;
//            cin>>skirstymas;
//
//
//            if (skirstymas==1)
//            {
//                vector<studentas> blogas;
//                skirstymas_trinant_vec(S, blogas);
//                stud_toFile_vec(S);
//
//            }
//            if (skirstymas==2)
//            {
//                vector<studentas> geras;
//                vector<studentas> blogas;
//                skirstymas_vec(S, stud_kiekis, geras, blogas);
//                stud_toFile_vec(geras);
//            }
//
//            cout<<"Faile issaugoti pazangus studentai.\n";

 return 0;
}
