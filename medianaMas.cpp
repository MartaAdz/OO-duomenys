#include <iostream>

using std::cout; using std::endl;

void mediana0(int M[], int kiek, int c){
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
