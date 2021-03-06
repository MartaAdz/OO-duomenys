﻿# Objektiškai orientuota Duomenų apdorojimo programa


## Naudojimosi instrukcija

Pasileidziame programa. 

1. Reikia sugeneruoti faila. Programa paklausia, kiek studentu noresime generuoti.
2. Programa informuoja, kad faile "kursas.dat" issaugoti pazangus studentai. T.y. tokie studentai, kuriu galutinis balas (naudojant vidurki) yra daugiau nei 5.
3. Programa paraso, kiek laiko uztruko programos vykdymas: 
- studentu konteinerio sukurimas, nuskaitymas is failo, 
- isrikiavimas pagal egzamino pažymį,
- suskirstymas i dvi grupes
- pazangiu studentu irasymas i faila

## Tyrimas

*Studentu failu generavimo laikai*

| Elementu skaicius  |   struct  |  class  |  class su -O1  |  class su -O2  |  class su -O3  |
|---|---|---|---|---|---|
| 100 | 0.004045 | 0 | 0.008324 | 0 | 0.003672 |
| 1000 | 0.037601 | 0.050548 | 0.03591 | 0.018759 | 0.014008 |
| 10000 | 0.377501 | 0.255678 | 0.303955 | 0.227008 | 0.307057 |
| 100000 | 4.13496 | 2.73485 | 2.64974 | 2.43884 | 2.67078 |

- Naudojant class programa vykdoma greiciau.
- Naudojant optimizavimo flag'us, programos vykdymo laikas sokinejo, nebuvo vieningos tendencijos. :D :D :D 


### Versija v0.1

#### Reikalavimai

1. `develop` branch'as.

2. Palyginti `struct` ir `class` realizacijų spartą.

3. Analizė priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us.

4. `master` ir `develop` merge'as.

#### Realizacija

1. `struct` perdaryta į `class`. Palyginta sparta.

2. Atliktas tyrimas su optimizavimo flag'ais.

3. Darbas su branch'ais. Sukurtas `develop` ir padarytas merge su `master`.



### Versija v0.2


#### Reikalavimai

1. doxygen dokumentacija

2. operatoriu overload'inimas

#### Realizacija

- Idetas `stable_partition` algoritmas

- Pašalinta kirstymo funkcija

### Versija v1.0


#### Reikalavimai

- Unit testai

#### Realizacija

- Padaryti unit testai naudojant Catch2 framework'a


### Cool dalykai

1. `Class` iskart greitesne nei `struct`
2. 
```cpp
  studentas::studentas(std::istream&duomenys){
      stud_fromFile(duomenys);
  }
```
3.
```cpp
int main()
{
        unsigned int stud_kiekis;
        stud_kiekis = 10000;
        const int paz_kiekis = 5;

        studentu_generavimas(stud_kiekis, paz_kiekis);

        std::ifstream duomenys("kursiokai.txt");

        try{
            if(duomenys.fail())
            {
                throw std::exception();
            }
        }
        catch (std::exception &e1)
        {   e1.what();
            std::cerr<<"Tokio failo nera. Baigiu programa.";
            exit(1);
        }

            std::vector<studentas> S;
            visi_toVec(duomenys, S, stud_kiekis);
            rikiavimas_vec(S);
            dvi_grupes(S);
            stud_toFile_vec(S);

        return 0;
 }

```

# Pastabeles

- Doxygen nepilnas
-- Updatinau - pridejau komentarus ir aprasymus
- Dvejojame kada reikia "dieviskosios trejybes" 
- Neveikia Unit testas
![alt text][logo]

[logo]:https://github.com/MartaAdz/OO-duomenys/blob/master/Unit_testing/u_test.PNG?raw=true "Unit test"
