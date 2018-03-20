#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "studentas.h"

using std::vector; using std::size_t; using std::list; using std::deque;

void skirstymas_vec(vector<studentas>& S, unsigned int stud_kiekis, vector<studentas>& geras, vector<studentas>& blogas){
    studentas tmp;
    for (size_t i=0; i<stud_kiekis; i++)
    {

            if (S[i].pazymiai[0]+S[i].pazymiai[1]+S[i].pazymiai[2]<18) ////10*3*60/100=18
            {
                S[i]=tmp;
                blogas.push_back(tmp);
            }
            else
            {
                S[i]=tmp;
                geras.push_back(tmp);
            }
    }
}
void skirstymas_list(list<studentas>& stud_list, unsigned int stud_kiekis,
                     list<studentas>& geri, list<studentas>& blogi){

    for (auto it=stud_list.begin(); it!=stud_list.end(); it++)
    {
            if ((*it).pazymiai[0]+(*it).pazymiai[1]+(*it).pazymiai[2]<18) blogi.push_back(*it); //10*3*60/100=18
            else geri.push_back(*it);
    }
}
void skirstymas_dek(deque<studentas>& S, unsigned int stud_kiekis, deque<studentas>& geri, deque<studentas>& blogi){
    studentas tmp;

    for (size_t i=0; i<stud_kiekis; i++)
    {

            if (S[i].pazymiai[0]+S[i].pazymiai[1]+S[i].pazymiai[2]<18) ////10*3*60/100=18
            {
                S[i]=tmp;
                blogi.push_back(tmp);
            }
            else
            {
                S[i]=tmp;
                geri.push_back(tmp);
            }
    }
}

