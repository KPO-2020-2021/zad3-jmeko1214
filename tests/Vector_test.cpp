#include "../tests/doctest/doctest.h"
#include "vector.hh"

#include <fstream>

TEST_CASE("Test konstruktora bezparametrycznego")
{
    Vector a;
    CHECK(a[0]==0);
    CHECK(a[1]==0);
}

TEST_CASE("Test konstruktora z parametrem")
{
    Vector a;
    double wek[2]={1,1};
    a=Vector(wek);
    CHECK(a[0]==1);
    CHECK(a[1]==1);
}

TEST_CASE("Test 1. Przeciazenie operatora porownania '==' ")
{
    Vector a,b,c;
    double wek1[2]={1,1},wek2[2]={1,1},wek3[2]={1,0};
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    CHECK(a==b);
    CHECK_FALSE(a==c);
}

TEST_CASE("Test 2. Przeciazenie operatora porownania '==' ")
{
    Vector a,b,c;
    double wek1[2]={1.00000000001,1.00000000001},wek2[2]={1,1},wek3[2]={1,0};
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    CHECK(a==b);
    CHECK_FALSE(a==c);
}

TEST_CASE("Test 1. Przeciazenie operatora porownania '!=' ")
{
    Vector a,b,c;
    double wek1[2]={1,1},wek2[2]={1,1},wek3[2]={1,0};
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    CHECK(a!=c);
    CHECK_FALSE(a!=b);
}

TEST_CASE("Test 2. Przeciazenie operatora porownania '!=' ")
{
    Vector a,b,c;
    double wek1[2]={1.00000000001,1.00000000001},wek2[2]={1,1},wek3[2]={1,0};
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    CHECK(a!=c);
    CHECK_FALSE(a!=b);
}

TEST_CASE("Test 1: Przeciazenie operatora dodawania")
{
    Vector a,b,c,d;
    double wek1[2]={4,2},wek2[2]={2,2},wek3[2]={6,4},wek4[2]={4,4};
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    d=Vector(wek4);
    CHECK(a+b==c);
    CHECK_FALSE(a+b==d);
}

TEST_CASE("Test 2: Przeciazenie operatora dodawania - dokladnosc")
{
    Vector a,b,c,d;
    double wek1[2]={4.0000000001,2.0000000001},wek2[2]={2,2},wek3[2]={6.0000000001,4.0000000001},wek4[2]={4,0};
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    d=Vector(wek4);
    CHECK(a+b==c);
    CHECK_FALSE(a+b==d);
}

TEST_CASE("Test 1: Przeciazenie operatora odejmowania")
{
    Vector a,b,c,d;
    double wek1[2]={4,2},wek2[2]={2,2},wek3[2]={2,0},wek4[2]={4,4};
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    d=Vector(wek4);
    CHECK(a-b==c);
    CHECK_FALSE(a-b==d);
}

TEST_CASE("Test 2: Przeciazenie operatora odejmowania - dokladnosc")
{
    Vector a,b,c,d;
    double wek1[2]={4.0000000001,2.0000000001},wek2[2]={2,2},wek3[2]={2.0000000001,0.0000000001},wek4[2]={4,0};
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    d=Vector(wek4);
    CHECK(a-b==c);
    CHECK_FALSE(a-b==d);
}


TEST_CASE("Test 1: Przeciazenie operatora mnozenia vector")
{
    Vector a,b,c;
    double wek1[2]={4,2},wek2[2]={8,4},wek3[2]={8,0},d=2;
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    CHECK(a*d==b);
    CHECK_FALSE(a*d==c);
}

TEST_CASE("Test 2: Przeciazenie operatora mnozenia vector")
{
    Vector a,b,c;
    double wek1[2]={0.33333333333,0.33333333333},wek2[2]={1,1},wek3[2]={0.9999999999,0.9999999999},d=3;
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    CHECK(a*d==b);
    CHECK_FALSE(a*d==c);
}

TEST_CASE("Test 1: Przeciazenie operatora dzielenia Vector")
{
    Vector a,b,c;
    double wek1[2]={4,2},wek2[2]={2,1},wek3[2]={2,0},d=3;
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    CHECK(a/d==b);
    CHECK_FALSE(a/d!=c);
}

TEST_CASE("Test 2: Przeciazenie operatora dzielenia Vector - dokladonsc")
{
    Vector a,b,c;
    double wek1[2]={5,5},wek2[2]={1.66666666667,1.66666666667},wek3[2]={1.6666667,1.6666667},d=3;
    a=Vector(wek1);
    b=Vector(wek2);
    c=Vector(wek3);
    CHECK(a/d==b);
    CHECK_FALSE(a/d!=c);
}

TEST_CASE("Test 3: Przeciazenie operatora dzielenia Vector - dzielenie przez '0'")
{
    Vector a;
    double wek[2]={4,2},b=0;
    a=Vector(wek);
    WARN_THROWS(a/b);
}

TEST_CASE("Test operatora []")
{
    Vector x,y,z;
    double wek1[2]={1,2},wek2[2]={3,4},wek3[2]={5,6};
    x=Vector(wek1);
    y=Vector(wek2);
    z=Vector(wek3);
    double a,b,c,d,e,f;
    a=1; b=2;
    c=3; d=4;
    e=5; f=6;

    CHECK(a==x[0]);
    CHECK(b==x[1]);
    CHECK(c==y[0]);
    CHECK(d==y[1]);
    CHECK(e==z[0]);
    CHECK(f==z[1]);
}

