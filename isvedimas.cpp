#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm>
#include "studentas.h"
#include "vidurkis.h"
#include "mediana.h"
#include "generavimas.h"

using std::cout; using std::cin; using std::endl; using std::vector;

    void pasirinkimas(studentas &S, vector<int> nDarbas, int kintamieji, int egzaminas ){
                int a;
                cin>>a;
                while(a!=1||a!=2)
                {
                    if(a==1)
                    {
                        auto kintamieji=nDarbas.size()-1;
                        auto nDarSuma=0;
                        for(int i=0; i<kintamieji; i++) nDarSuma+=nDarbas[i];
                        S.galBalasVid=vidurkis(nDarSuma, kintamieji, egzaminas);
                        cout.precision(3);
                        cout<<S.galBalasVid;
                        break;
                    }

                    else if(a==2)
                    {
                        S.galBalasMed=mediana (nDarbas, kintamieji, egzaminas);
                        cout.precision (3);
                        cout<<S.galBalasMed;
                        break;
                    }

                    else
                    {
                        cout<<"Neteisingai ivestas pasirinkimas\nIveskite is naujo"<<endl;
                        cin>>a;
                    }

                    break;
            }
        }
