#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include "studentas.h"

using std::vector; using std::size_t; using std::list; using std::deque;

void skirstymas_vec(vector<studentas>& S, unsigned int stud_kiekis, vector<studentas>& geras, vector<studentas>& blogas){

    for (size_t i=0; i!=stud_kiekis; i++)
    {
            if (S[i].galBalasVid<5) blogas.push_back(S[i]);
            else geras.push_back(S[i]);
    }
}
vector<studentas> skirstymas_trinant_vec(vector<studentas>& S, vector<studentas>& blogas){
    vector<studentas>::iterator it = S.begin();
    while (it!=S.end())
    {
        if ((*it).galBalasVid<5)
        {
            blogas.push_back(*it);
            it=S.erase(it);
        }
        else it++;
    }
    return blogas;
}
void skirstymas_list(list<studentas>& stud_list,
                     list<studentas>& geri, list<studentas>& blogi){

    for (auto it=stud_list.begin(); it!=stud_list.end(); it++)
    {
            if ((*it).galBalasVid<5) blogi.push_back(*it);
            else geri.push_back(*it);
    }
}
list<studentas> skirstymas_trinant_list (list<studentas>& stud_list, list<studentas>& blogi){

    list<studentas>::iterator it=stud_list.begin();
    while (it!=stud_list.end())
    {
        if ((*it).galBalasVid<5)
        {
            blogi.push_back(*it);
            it=stud_list.erase(it);
        }
        else it++;
    }
    return blogi;
}
void skirstymas_dek(deque<studentas>& S, unsigned int stud_kiekis, deque<studentas>& geri, deque<studentas>& blogi){

    for (size_t i=0; i<stud_kiekis; i++)
    {

            if (S[i].galBalasVid<5)  blogi.push_back(S[i]);
            else geri.push_back(S[i]);
    }
}
bool arGeras(studentas &S) {
     if (S.galBalasVid>=5) return true;
}
bool arBlogas(studentas &S) {
    if (S.galBalasVid<5) return true;
    }
deque<studentas> skirstymas_trinant_dek(deque<studentas>& stud_dek, deque<studentas>& blogi){

    std::remove_copy_if(stud_dek.begin(), stud_dek.end(), std::back_inserter(blogi), arGeras);
    stud_dek.erase(remove_if(stud_dek.begin(), stud_dek.end(), arBlogas), stud_dek.end());
    return blogi;
}

