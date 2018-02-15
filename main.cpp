#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;
void vidurkis(int a, int b, int c){
    double galBalas=0.4*(a/b)+0.6*c;
    cout.precision (3);
    cout<<galBalas;
}
void mediana(double M[], int kiek, int c){
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
        cout<<galBalas<<endl;
    }
    else
    {
        auto galBalas=0.4*(M[j / 2] + M[j / 2 +1])/2+0.6*c;
        cout.precision (3);
        cout<<galBalas<<endl;
    }

}

int main()
{
    cout<<"Iveskite studento varda: ";
    string vardas;
    cin>>vardas;

    cout<<"Iveskite pazymius. (Pabaigus ivesti -1)"<<endl;
    auto kintamieji=0;                                      //kintamuju kiekis
    auto talpa=1;                                           //kiek masyve gali tilpti elementu
    double *nDarbas = new double [talpa];                   //masyvas namu darbu pazymiais saugoti

    auto i=0;                                               //masyvo elementu skaicius
    for(i=0; i<talpa; i++)                                  //ivedame pazymius
    {
        cout<<i+1<<" pazymys: ";
        cin>>nDarbas[i];
        kintamieji++;                                       //padidiname kintamuju kieki vienu elementu
        talpa++;                                            //padidiname talpa vienu elementu

        if (nDarbas[i]==-1) break;
    }

    auto nDarSuma=0;
    for(int i=0; i<kintamieji; i++) nDarSuma+=nDarbas[i];   //suskaiciuojame visu pazymiu suma

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

    return 0;
}
