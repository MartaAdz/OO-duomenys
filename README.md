# Objektiškai orientuota Duomenų apdorojimo programa


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

| Elementu skaicius  |   struct  |  class  |  -O1  |  -O2  |  -O3  |
|---|---|---|---|---|---|
| 100 | 0.004045 | 0.00601 | 0.004324 | 0.003984 | 0.05252 |
| 1000 | 0.037601 | 0.006894 | 0.019054 | 0.016365 | 0.034318 |
| 10000 | 0.377501 | 0.250615 | 0.343647 | 0.357715 | 0.310707 |
| 100000 | 4.13496 | 2.95832 | 3.56122 | 3.71297 | 3.80577 |

- Naudojant class programa vykdoma greiciau.
- Naudojant optimizavimo flag'us, programos vykdymo laikas pailgejo. :D :D :D 


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























