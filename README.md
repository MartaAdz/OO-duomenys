# Duomenys


## Versija v0.1

### Reikalavimai

1. Pagal užduoties reikalavimus relizuokite programa ir atspausdinkite ekrane aktualia informacija:
-studento varda ir pavarde,
-namu darbu ir egzamino rezultatus
-galutini bala dvieju skaiciu po kablelio tikslumu

2. Papildykite programa, kad vietoj vidurkio butu galima naudoti mediana.

3. Papildykite programa? taip, kad ji veiktu? ir tokiu atveju, kai namu? darbu? skaic?ius (n) yra nez?inomas is? anksto, 
t.y. tik i?vedimo metu vartotojas nuspre?ndz?ia kuomet jis jau i?vede? visu? namu? darbu? rezultatus. S?ia? uz?duoti? (papildyma?) realizuoti reiktu? dviem bu¯dais:
-naudojant C masyvus.
-naudojant vector ar kito tipo konteineri?.

4. Papildykite programa? taip, kad bu¯tu? galimybe?, jog mokinio gautieji balai uz? namu? darbus bei egzamina? bu¯tu? generuojami atsitiktinai.

## Versija v0.2

### Reikalavimai

1. Duomenis ne tik i?vesti, bet ir nuskaityti is? failu?.

2. Nuskaic?iuoti duomenis is? failo. Reikalavimai output’ui: studentai turi bu¯tui suru¯s?iuoti pagal vardus (ar pavardes) ir stulpeliai bu¯tu? graz?iai "is?lygiuoti".

## Versija v0.3

### Reikalavimai

1. Kur tikslinga, programoje naudokite (jeigu dar nenaudojote) struct'uras

2. Funkcijas, naujus duomenu? tipus (struct’u¯ras) perkelkite i? antras?tinius (angl. header (*.h)) failus.

3. Kur tikslinga, panaudokite išimciu valdyma (angl. Exception Handling)

## Versija v0.4

### Reikalavimai

1. Sugeneruokite penkis atsitiktinius studentu? failus, sudarytus is?: 100, 1000, 10000, 100000 i?ras?u?. Vardus ir Pavardes generuoti "šabloninius" (Vardas1 Pavarde1, Vardas2 Pavarde2 ir t.t.)
2. Su¯rus?iuokite (padalinkite) studentus i? dvi kategorijas:
- Studentai, kurie surinko < 5 uz? namu? darbu? uz?duotis
- Studentai, kurie surinko >= 5 uz? namu? darbu? uz?duotis ir buvo prileisti prie egzamino.
3. Is?matuokite visos programos (t.y. failu sukurima irgi reikia matuoti) veikimo laika? testuojant su s?iais keturiais skirtingo dydz?io duomenu? failais.

##Versija v0.5

### Reikalavimai

1.Is?matuokite programos veikimo sparta (be failu generavimo) priklausomai nuo naudojamo vieno iš triju konteineriu:
- vector
- list
- deque

## Versija v1.0

### Reikalavimai

1. Visiems trims konteineriu tipams (vector, list ir deque) is?matuokite programos veikimo sparta priklausomai nuo studentu dalijimo i dvi kategorijas strategijos:

- Bendro studentai konteinerio skaidymas (rušiavimas) panaudojant du naujus konteinerius: "vargšiuku" ir "kietiaku". Tokiu budu tas pats studentas yra dvejuose konteineriuose: studentai ir (vargšiukai arba kietiakai). 
- Bendro studentu konteinerio skaidymas (rušiavimas) panaudojant tik viena nauja konteineri: "vargšiukai". Tokiu budu, jei studentas yra vargšiukas, ji turime ikelti i "vargšiuku" konteineri ir ištrinti ir bendro studentai konteinerio. Tokiu budu, studentai konteineryje liks vien tik kietiakai.




















