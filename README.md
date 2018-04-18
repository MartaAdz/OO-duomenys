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

| Elementu skaicius  |   struct  |  class  | 
|---|---|---|---|
| 100 | 0.004045 | 0.00601 | 
| 1000 | 0.037601 | 0.006894 |
| 10000 | 0.377501 | 0.250615 |
| 100000 | 4.13496 | 2.95832 | 


### Versija v0.1

#### Reikalavimai

1. `develop` branch'as.

2. Palyginti `struct` ir `class` realizacijų spartą.

3. Analizė priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us.

4. `master` ir `develop` merge'as.

#### Realizacija

1. `struct` perdaryta į `class`.
2.  























