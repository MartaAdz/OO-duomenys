#include <iostream>

void vidurkis(int a, int b, int c){
    double galBalas=0.4*(a/b)+0.6*c;
    std::cout.precision (3);
    std::cout<<"Galutinis balas: "<<galBalas;
}
