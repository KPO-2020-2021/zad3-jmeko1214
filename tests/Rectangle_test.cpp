#include "../tests/doctest/doctest.h"
#include "rectangle.hh"
#include "vector.hh"

#include <fstream>

TEST_CASE("Test porownania '==' 1")
{
    Prostokat A, B;

    A[0][0] = 3;     A[0][1] = 1;
    A[1][0] = 4;     A[0][1] = 1;
    A[2][0] = 5;     A[0][1] = 4;
    A[3][0] = 9;     A[0][1] = 2;

    B[0][0] = 3;     B[0][1] = 1;
    B[1][0] = 4;     B[0][1] = 1;
    B[2][0] = 5;     B[0][1] = 4;
    B[3][0] = 9;     B[0][1] = 2;
    
    CHECK(A == B);
}

TEST_CASE("Test porownania '==' 2")
{
    Prostokat A, B;

    A[0][0] = 3;     A[0][1] = 1;
    A[1][0] = 4;     A[1][1] = 2;
    A[2][0] = 5;     A[2][1] = 4;
    A[3][0] = 3;     A[3][1] = 2;

    B[0][0] = 4;     B[0][1] = 4;
    B[1][0] = 3;     B[1][1] = 1;
    B[2][0] = 6;     B[2][1] = 5;
    B[3][0] = 9;     B[3][1] = 1;
    
    CHECK_FALSE(A == B);
}

TEST_CASE("Test porownania '!=' 1")
{
    Prostokat A, B;

    A[0][0] = 3;     A[0][1] = 1;
    A[1][0] = 4;     A[1][1] = 1;
    A[2][0] = 5;     A[2][1] = 4;
    A[3][0] = 9;     A[3][1] = 2;

    B[0][0] = 3;     B[0][1] = 1;
    B[1][0] = 4;     B[1][1] = 1;
    B[2][0] = 5;     B[2][1] = 4;
    B[3][0] = 9;     B[3][1] = 2;
    
    CHECK_FALSE(A != B);
}

TEST_CASE("Test porownania '!=' 2")
{
    Prostokat A, B;

    A[0][0] = 3;     A[0][1] = 1;
    A[1][0] = 4;     A[1][1] = 2;
    A[2][0] = 5;     A[2][1] = 4;
    A[3][0] = 3;     A[3][1] = 2;

    B[0][0] = 3;     B[0][1] = 1;
    B[1][0] = 4;     B[1][1] = 1;
    B[2][0] = 5;     B[2][1] = 4;
    B[3][0] = 9;     B[3][1] = 2;
    
    CHECK(A == B);
}


TEST_CASE("Test przesuniecia 1")
{
    Prostokat A, B;
    double wek[]={0,0};
    Vector vek(wek);

    A[0][0] = 3;     A[0][1] = 1;
    A[1][0] = 4;     A[1][1] = 1;
    A[2][0] = 5;     A[2][1] = 4;
    A[3][0] = 9;     A[3][1] = 2;

    B[0][0] = 3;     B[0][1] = 1;
    B[1][0] = 4;     B[1][1] = 1;
    B[2][0] = 5;     B[2][1] = 4;
    B[3][0] = 9;     B[3][1] = 2;

    A.Przesuniecie(vek);
    
    CHECK(A == B);
}

TEST_CASE("Test przesuniecia 2")
{
    Prostokat A, B;
    double wek[]={2,1};
    Vector vek(wek);

    A[0][0] = 3;     A[0][1] = 1;
    A[1][0] = 4;     A[1][1] = 1;
    A[2][0] = 5;     A[2][1] = 4;
    A[3][0] = 9;     A[3][1] = 2;

    B[0][0] = 5;     B[0][1] = 2;
    B[1][0] = 6;     B[1][1] = 2;
    B[2][0] = 7;     B[2][1] = 5;
    B[3][0] = 11;    B[3][1] = 3;

    A.Przesuniecie(vek);
    
    CHECK(A == B);
}

TEST_CASE("Test przesuniecia 3")
{
    Prostokat A, B;
    double wek[]={-2,-5};
    Vector vek(wek);

    A[0][0] = 3;     A[0][1] = 1;
    A[1][0] = 4;     A[1][1] = 1;
    A[2][0] = 5;     A[2][1] = 4;
    A[3][0] = 9;     A[3][1] = 2;

    B[0][0] = 1;     B[0][1] = -4;
    B[1][0] = 2;     B[1][1] = -4;
    B[2][0] = 3;     B[2][1] = -1;
    B[3][0] = 7;     B[3][1] = -3;

    A.Przesuniecie(vek);
    
    CHECK(A == B);
}

TEST_CASE("Test obrotu o kat 1")
{
    Prostokat A, B;
    double kat=90;

    A[0][0] = -2;    A[0][1] = 1;
    A[1][0] = 2;     A[1][1] = 1;
    A[2][0] = 2;     A[2][1] = -1;
    A[3][0] = -2;    A[3][1] = -1;

    B[0][0] = 1;     B[0][1] = 2;
    B[1][0] = 1;     B[1][1] = -2;
    B[2][0] = -1;    B[2][1] = -2;
    B[3][0] = -1;    B[3][1] = 2;

    A.Obrot(kat);
    
    CHECK(A == B);
}

TEST_CASE("Test obrotu o kat 2")
{
    Prostokat A, B;
    double kat=-90;

    A[0][0] = -2;    A[0][1] = 1;
    A[1][0] = 2;     A[1][1] = 1;
    A[2][0] = 2;     A[2][1] = -1;
    A[3][0] = -2;    A[3][1] = -1;

    B[0][0] = -1;    B[0][1] = -2;
    B[1][0] = -1;    B[1][1] = 2;
    B[2][0] = 1;     B[2][1] = 2;
    B[3][0] = 1;     B[3][1] = -2;

    A.Obrot(kat);
    
    CHECK(A == B);
}

TEST_CASE("Test obrotu o kat 3")
{
    Prostokat A, B;
    double kat=360;

    A[0][0] = -2;    A[0][1] = 1;
    A[1][0] = 2;     A[1][1] = 1;
    A[2][0] = 2;     A[2][1] = -1;
    A[3][0] = -2;    A[3][1] = -1;

    B[0][0] = -2;    B[0][1] = 1;
    B[1][0] = 2;     B[1][1] = 1;
    B[2][0] = 2;     B[2][1] = -1;
    B[3][0] = -2;    B[3][1] = -1;

    A.Obrot(kat);
    
    CHECK(A == B);
}
