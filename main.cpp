#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;
using std::setw; using std::swap;

int main()
{
    cout<<"1-nuskaityti is failo, 2-ivesti ranka. \n";
    int p;
    cin>>p;

    if(p==1){
        vector<studentas> S;
        string var, pav;
        vector <int> paz (3,0);
        int egz;
        auto i=0;
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


        while(! duomenys.eof())
        {
            duomenys >> var >> pav >> paz[0] >> paz[1] >> paz[2] >> egz;
            S.push_back(studentas());
            S[i].vardas=var;
            S[i].pavarde=pav;
            S[i].pazymiai.push_back(paz[0]);
            S[i].pazymiai.push_back(paz[1]);
            S[i].pazymiai.push_back(paz[2]);
            S[i].egzaminas=egz;
            i++;
        }
        cout<<std::left<<setw(20)<<"Vardas"
                        <<setw(20)<<"Pavarde"
                        <<setw(20)<<"Galutinis-vidurkis"
                        <<setw(20)<<"Galutinis-mediana"
                        <<"\n";
        for(int j = 0; j < i; j++) //rikiuojame studentus pagal pavarde
        {
            int k=j;
            while (S[k].pavarde < S[k - 1].pavarde)
            {
                swap(S[k], S[k - 1]);
                k--;
            }
        }
        for(int j=0; j<i;j++)
        {
            cout<<std::left<<setw(20)<<S[j].vardas
                        <<setw(20)<<S[j].pavarde;
            vidurkis(S[j]);
            mediana(S[j]);
            cout<<"\n";
        }
    }
    else if(p==2) {
        vector<studentas> S;
        cout<<"Iveskite studento varda ir pavarde: ";
        string var, pav;
        cin>>var;
        cin>>pav;

        S[1].vardas=var;
        cout<<"1-generuoti pazymius, 2-ivesti pazymius. ";
        int p;
        cin>>p;

        vector<int> nDarbas;
        int pazymys;

        if(p==1){

            cout<<"Kiek pazymiu norite sugeneruoti?";
            int kiekis;
            cin>>kiekis;
            cout<<"Pazymiai: "<<endl;

            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<> dis(1, 10);


            for(int i=0; i<kiekis; i++)
            {
                cout<<i+1<<" pazymys: ";
                pazymys=dis(gen);
                cout<<pazymys<<" ";
                nDarbas.push_back(pazymys);
            }

            auto kintamieji=nDarbas.size()-1;
            auto nDarSuma=0;
            for(int i=0; i<kintamieji; i++) nDarSuma+=nDarbas[i];

            int egzaminas=dis(gen);
            cout<<"\nEgzamino pazymys: "<<egzaminas;

            cout<<endl;
            cout<<"Skaiciuojame galutini bala\n1-Naudoti vidurki\n2-Naudoti mediana"<<endl;

            int a;
            cin>>a;
            while(a!=1||a!=2)
            {
                if(a==1)
                {
                    vidurkis(nDarSuma, kintamieji, egzaminas);
                    break;
                }

                else if(a==2)
                {
                    mediana (nDarbas, kintamieji, egzaminas);
                    break;
                }

                else
                {
                    cout<<"Neteisingai ivestas pasirinkimas\nIveskite is naujo"<<endl;
                    cin>>a;
                }
            }}
        else if (p==2)
        {
            cout<<"Iveskite pazymius. (Pabaigus ivesti -1)"<<endl;

            for(int i=0; i<nDarbas.size()+1; i++)
            {
                cout<<i+1<<" pazymys: ";
                cin>>pazymys;
                nDarbas.push_back(pazymys);

                if (pazymys==-1) break;
            }

            auto kintamieji=nDarbas.size()-1;
            auto nDarSuma=0;
            for(int i=0; i<kintamieji; i++) nDarSuma+=nDarbas[i];

            cout<<endl;
            cout<<"Iveskite egzamino pazymi: ";
            int egzaminas;
            cin>>egzaminas;

            cout<<endl;
            cout<<"Skaiciuojame galutini bala\n1-Naudoti vidurki\n2-Naudoti mediana"<<endl;

            int a;
            cin>>a;
            while(a!=1||a!=2)
            {
                if(a==1)
                {
                    vidurkis(nDarSuma, kintamieji, egzaminas);
                    break;
                }

                else if(a==2)
                {
                    mediana (nDarbas, kintamieji, egzaminas);
                    break;
                }

                else
                {
                    cout<<"Neteisingai ivestas pasirinkimas\nIveskite is naujo"<<endl;
                    cin>>a;
                }

                break;
        }}

    }
 return 0;
}




