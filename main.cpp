#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
    cout<<"Iveskite studento varda: ";
    string vardas;
    cin>>vardas;

    int nDarbas[10]; //masyvas namu darbu pazymiais saugoti
    for(int i=0; i<5; i++) //ivedame 5 pazymius
    {
        cout<<"Iveskite "<<i+1<<" pazymi: ";
        cin>>nDarbas[i];
    }

    int nDarSuma=0;
    for(int i=0; i<5; i++) nDarSuma+=nDarbas[i];

    cout<<endl;
    cout<<"Iveskite egzamino pazymi: ";
    int egzaminas;
    cin>>egzaminas;

    double galBalas=0.4*(nDarSuma/5)+0.6*egzaminas;
    cout.precision (3);
    cout<<galBalas;

    return 0;
}
