#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;
void vidurkis(int a, int b, int c){
    double galBalas=0.4*(a/b)+0.6*c;
    cout.precision (3);
    cout<<"Galutinis balas: "<<galBalas;
}
void mediana(int M[], int kiek, int c){
    int j;
	for (int i = 1; i < kiek; i++)
	{
		j = i;
		while (j > 0 && M[j] < M[j - 1])
		{
			std::swap(M[j], M[j - 1]); //rikiuojame pazymius
			j--;
		}
	}

    if (j%2==0)
    {
        auto galBalas=0.4*M[j / 2]+0.6*c;
        cout.precision (3);
        cout<<"Galutinis balas: "<<galBalas<<endl;
    }
    else
    {
        auto galBalas=0.4*(M[j / 2] + M[j / 2 +1])/2+0.6*c;
        cout.precision (3);
        cout<<"Galutinis balas: "<<galBalas<<endl;
    }

}
void mediana(vector<int>& M, int kiek, int c){
    int j;
	for (int i = 1; i < kiek; i++)
	{
		j = i;
		while (j > 0 && M[j] < M[j - 1])
		{
			std::swap(M[j], M[j - 1]); //rikiuojame pazymius
			j--;
		}
	}

    if (j%2==0)
    {
        auto galBalas=0.4*M[j / 2]+0.6*c;
        cout.precision (3);
        cout<<"Galutinis balas: "<<galBalas<<endl;
    }
    else
    {
        auto galBalas=0.4*(M[j / 2] + M[j / 2 +1])/2+0.6*c;
        cout.precision (3);
        cout<<"Galutinis balas: "<<galBalas<<endl;
    }

}
int main()
{
   cout<<"Iveskite studento varda ir pavarde: ";
    string vardas;
    cin>>vardas;

    cout<<"1-naudoti masyvus\n2-naudoti vektorius"<<endl;
    int c;
    cin>>c;
    while(c!=1||c!=2){
        if (c==1){
            cout<<"1-generuoti pazymius, 2-ivesti pazymius.";
            int p;
            cin>>p;

            auto kintamieji=0;                                      //kintamuju kiekis
            auto talpa=1;                                           //kiek masyve gali tilpti elementu
            int *nDarbas = new int [talpa];

            if(p==1){
                cout<<"Kiek pazymiu norite sugeneruoti?";
                int kiekis;
                cin>>kiekis;
                cout<<"Pazymiai: "<<endl;

                std::random_device rd;  //Will be used to obtain a seed for the random number engine
                std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
                std::uniform_int_distribution<> dis(1, 10);

                for (int i=0; i<kiekis; i++)
                {
                    nDarbas[i]=dis(gen);
                    cout << nDarbas[i] << ' ';
                }

                auto nDarSuma=0;
                for(int i=0; i<kintamieji; i++) nDarSuma+=nDarbas[i];

                cout<<endl;

                int egzaminas=dis(gen);
                cout<<"egzamino pazymys: "<<egzaminas;

                cout<<endl;
                cout<<"Skaiciuojame galutini bala\n1-Naudoti vidurki\n2-Naudoti mediana"<<endl;
                int a;
                cin>>a;
                while(a!=1||a!=2)
                {
                    if(a==1)
                    {
                        vidurkis(nDarSuma, kiekis, egzaminas);
                        break;
                    }

                    else if(a==2)
                    {
                        mediana (nDarbas, kiekis, egzaminas);
                        break;
                    }

                    else
                    {
                        cout<<"Neteisingai ivestas pasirinkimas\nIveskite is naujo"<<endl;
                        cin>>a;
                    }

                }
                break;
                }

            else if (p==2){
                cout<<"Iveskite pazymius. (Pabaigus ivesti -1)"<<endl;


                auto i=0;
                                                              //masyvo elementu skaicius
                for(i=0; i<talpa; i++)
                {
                    cout<<i+1<<" pazymys: ";
                    cin>>nDarbas[i];
                    kintamieji++;
                    talpa++;

                    if (nDarbas[i]==-1) break;
                }

                auto nDarSuma=0;
                for(int i=0; i<kintamieji; i++) nDarSuma+=nDarbas[i];   //pazymiu suma

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
                        vidurkis(nDarSuma, i, egzaminas);
                        break;
                    }

                    else if(a==2)
                    {
                        mediana (nDarbas, i, egzaminas);
                        break;
                    }

                    else
                    {
                        cout<<"Neteisingai ivestas pasirinkimas\nIveskite is naujo"<<endl;
                        cin>>a;
                    }

                }
                    break;
            }
        }

        else if (c==2)
        {   cout<<"1-generuoti pazymius, 2-ivesti pazymius.";
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
                    }
                    break;
                    }

        else
        {
            cout<<"Neteisingai ivestas pasirinkimas\nIveskite is naujo"<<endl;
            cin>>c;
        }
    }}


    return 0;
}

