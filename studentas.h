#ifndef _STUDENTAS_H
#define _STUDENTAS_H
#include <string>
#include <algorithm>
#include <iomanip>
#include<vector>
class studentas{
    private:
        std::string vardas;
        std::string pavarde;
        std::vector <int> pazymiai;
        int egzaminas;
        double galBalasMed;
        double galBalasVid;
        int pazymiu_kiekis;

    public:

//        void nuskaitymas(std::vector<studentas>& S, std::ifstream &duomenys, int paz_kiekis);
//        void rikiavimas(std::vector<studentas>&S) {std::sort(S.begin(), S.end(), lyginimas);}
//        std::vector<studentas> skirstymas_trinant(std::vector<studentas>& S, std::vector<studentas>& blogi);
//        void stud_toFile(std::vector<studentas>& S);

        double vidurkis( ){
            auto nDarSuma=0;
            for(int i=0; i<pazymiu_kiekis; i++) nDarSuma+=pazymiai[i];
            double galBalasVid=0.4 * (nDarSuma/pazymiu_kiekis)+0.6 * egzaminas;
            return galBalasVid;
        }

        double mediana(){
            int j;
            for (int i = 1; i < pazymiu_kiekis; i++)
            {
                j = i;
                while (j > 0 && pazymiai[j] < pazymiai[j - 1])
                {
                    std::swap(pazymiai[j], pazymiai[j - 1]); //rikiuojame pazymius
                    j--;
                }
            }

            if (j%2==0)
            {
                auto galBalasMed=0.4*pazymiai[j / 2]+0.6*egzaminas;
                return galBalasMed;
            }
            else
            {
                auto galBalasMed=0.4*(pazymiai[j / 2] + pazymiai[j / 2 +1])/2+0.6*egzaminas;
                return galBalasMed;
            }
        }
//
//    void nuskaitymas(std::vector<studentas>& S, std::ifstream &duomenys, int paz_kiekis){
//
//        std::string var, pav;
//        std::vector <int> paz (paz_kiekis, 0);
//        int egz;
//
//        while(!duomenys.eof())
//        {
//            duomenys >> var >> pav;
//            for(int i=0; i<paz_kiekis; i++) duomenys>> paz[i];
//            duomenys >> egz;
//            studentas stud;
//            stud.vardas=var;
//            stud.pavarde=pav;
//            for (auto i=0; i!=paz_kiekis; i++) stud.pazymiai.push_back(paz[i]);
//            stud.egzaminas=egz;
//
//            S.push_back(stud);
//        }
//    }
//
//
//    void stud_toFile(std::vector<studentas>& S){
//
//        std::ofstream f("kursas.dat");
//        f<<std::left<<std::setw(20)<<"Vardas"
//                            <<std::setw(20)<<"Pavarde"
//                            <<std::setw(20)<<"Galutinis-vidurkis"
//                            <<std::setw(20)<<"Galutinis-mediana"
//                            <<"\n";
//        for(size_t c=0; c < S.size() ; c++)
//        {
//                f<<std::left<<std::setw(20)<<S[c].vardas
//                            <<std::setw(20)<<S[c].pavarde
//                            <<std::setw(20)<<std::fixed<<std::setprecision(2)<<S[c].galBalasVid
//                            <<std::setw(20)<<std::fixed<<std::setprecision(2)<<S[c].galBalasMed<<std::endl;
//        }
//    }
//

};

//bool lyginimas (const studentas &rhs, const studentas &lhs) { return lhs.pavarde>rhs.pavarde;}
//bool arGeras(studentas &S) {
//     if (S.galBalasVid>=5) return true;
//}
//bool arBlogas(studentas &S) {
//    if (S.galBalasVid<5) return true;
//    }
//std::vector<studentas> skirstymas_trinant(std::vector<studentas>& S, std::vector<studentas>& blogi){
//
//        std::remove_copy_if(S.begin(), S.end(), std::back_inserter(blogi), arGeras);
//        S.erase(remove_if(S.begin(), S.end(), arBlogas), S.end());
//        return blogi;
//    }
#endif
