#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "funkcijos.h"
#include <fstream>


TEST_CASE( "Studento nuskaitymas" ) {  //istestuoja ar vyksta funkcija stud_toFile ir ar veikia konstruktorius

    std::ifstream  f ( "test.txt" );
    studentas s (f);
    SECTION("Vardas"){
        REQUIRE( s.getVardas() == "Vardas1" );
    }
    SECTION( "Studento pavarde " ){
        REQUIRE( s.getPavarde() == "Pavarde1" );
    }
    SECTION("Studento egzaminas"){
        REQUIRE( s.getEgzaminas() == 5 );
    }
    SECTION("Studento galutinis balas"){
        REQUIRE( s.getBalas() == 5.0 );
    }

}


