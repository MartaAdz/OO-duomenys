#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm>
#include <list>
#include <ctime>
#include <ratio>
#include <chrono>
#include <deque>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"
#include "generavimas.h"
#include "isvedimas.h"
#include "nuskaitymas.h"
#include "rikiavimas.h"
#include "skirstymas.h"

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;
using std::setw; using std::swap; using std::list; using std::deque;
int main()
{
    cout<<"1-nuskaityti is failo, 2-ivesti ranka. \n";

    int p;
    cin>>p;

    if(p==1){

        unsigned int stud_kiekis;
        cout<<"kiek studentu sugeneruoti: ";
        cin>>stud_kiekis;

        studentu_generavimas(stud_kiekis);

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

        using namespace std::chrono;
        high_resolution_clock::time_point t_dek_1 = high_resolution_clock::now();

        deque<studentas> stud_dek;
        nuskaitymas_dek(stud_dek, duomenys);
        stud_toFile_deque(stud_dek);


        high_resolution_clock::time_point t_dek_2 = high_resolution_clock::now();
        duration<double> time_dek = duration_cast<duration<double>>(t_dek_2 - t_dek_1);
        std::cout << "su deque uztruko " << time_dek.count() << " sekundziu.\n";


//        high_resolution_clock::time_point t_list_1 = high_resolution_clock::now();
//
//        list<studentas> stud_list;
//        nuskaitymas_list(stud_list, duomenys);
//        rikiavimas_list(stud_list);
//        //stud_isvedimas_list(stud_list);
//        stud_toFile_list(stud_list);
//        //skirstymas_list(stud_list, stud_kiekis);
//
//        high_resolution_clock::time_point t_list_2 = high_resolution_clock::now();
//        duration<double> time_list = duration_cast<duration<double>>(t_list_2 - t_list_1);
//        std::cout << "su listu uztruko " << time_list.count() << " sekundziu.\n";

//        high_resolution_clock::time_point t_vec_1 = high_resolution_clock::now();
//
//        vector<studentas> S;
//        nuskaitymas_vec (S, stud_kiekis, duomenys);
//        rikiavimas_vec(S);
//        //stud_isvedimas_vec(S);
//        stud_toFile_vec(S);
//
//        high_resolution_clock::time_point t_vec_2 = high_resolution_clock::now();
//        duration<double> time_vec = duration_cast<duration<double>>(t_vec_2 - t_vec_1);
//        std::cout << "su vektoriumi uztruko " << time_vec.count() << " sekundziu.";
//
//        vector<studentas> geras;
//        vector<studentas> blogas;
//        skirstymas_vec(S, stud_kiekis, geras, blogas);


    }
    else if(p==2) {
        auto d=1;
        auto i=0;
        vector<studentas> S;
        S.push_back(studentas());
        while(d!=2){

            cout<<"Iveskite studento varda ir pavarde: ";
            string var, pav;
            cin>>var;
            S[i].vardas=var;
            cin>>pav;
            S[i].pavarde=pav;

            cout<<"1-generuoti pazymius, 2-ivesti pazymius: ";
            int p;
            cin>>p;


            if(p==1){

                cout<<"Kiek pazymiu norite sugeneruoti?";
                int kiekis;
                cin>>kiekis;

                iverciai (S[i],kiekis);
                for(int j=1;j<kiekis;j++) cout<<S[i].pazymiai[j]<<" "; //isveda pazymius
                cout<<"\n";
                pasirinkimas(S[i]);

            }
             else if (p==2)
            {
                cout<<"Iveskite pazymius. (Pabaigus ivesti -1)"<<endl;
                int pazymys;
                for(int j=0; i<S[i].pazymiai.size()+1; j++)
                {
                    cout<<j+1<<" pazymys: ";
                    cin>>pazymys;
                    S[i].pazymiai.push_back(pazymys);

                    if (pazymys==-1) break;
                }

                cout<<"Iveskite egzamino pazymi: ";
                int egzaminas;
                cin>>egzaminas;
                S[i].egzaminas=egzaminas;

                pasirinkimas(S[i]);
            }
        i++;
        S.push_back(studentas());
        cout<<"\n1 - testi duomenu ivedima, 2 - baigti duomenu ivedima: ";
        cin>>d;
    }
}

 return 0;
}
