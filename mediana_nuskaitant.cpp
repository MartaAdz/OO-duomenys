#include <iostream>
#include <iomanip>
#include <vector>
#include "studentas.h"

using std::cout; using std::endl; using std::setw;

void mediana1(struct studentas &S){
    int j;
    auto kiek=S.pazymiai.size()-1;
	for (int i = 1; i < kiek; i++)
	{
		j = i;
		while (j > 0 && S.pazymiai[j] < S.pazymiai[j - 1])
		{
			std::swap(S.pazymiai[j], S.pazymiai[j - 1]); //rikiuojame pazymius
			j--;
		}
	}

    if (j%2==0)
    {
        auto galBalas=0.4*S.pazymiai[j / 2]+0.6*S.egzaminas;
        cout.precision (3);
        cout<<setw(20)<<galBalas;
    }
    else
    {
        auto galBalas=0.4*(S.pazymiai[j / 2] + S.pazymiai[j / 2 +1])/2+0.6*S.egzaminas;
        cout.precision (3);
        cout<<setw(20)<<galBalas;
    }

}

