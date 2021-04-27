#include "../tests/doctest/doctest.h"
#include "vector.hh"

#include <fstream>

TEST_CASE("Test konstruktora bezparametrycznego")
{
    Vector double a,b;
    CHECK(a, b(0,0));
}

TEST_CASE("Test konstruktora z parametrem")
{
    Vector int a(1, 1),b;
    CHECK(a, b(1,1));
}

TEST_CASE("Test 1. Przeciazenie operatora porownania '==' ")
{
    Vector int a(1,1), b;
    CHECK(a==b(1,1));
    CHECK_FALSE(a==b(2,1));
}

TEST_CASE("Test 2. Przeciazenie operatora porownania '==' ")
{
    Vector int a(1.0000000001,2.0000000001),b;
    CHECK(a==b(1,2));
    CHECK_FALSE(a==b(1.00000001,1.99999999));
}

TEST_CASE("Test 1. Przeciazenie operatora porownania '!=' ")
{
    Vector int a(1,1), b;
    CHECK_FALSE(a==b(1,1));
    CHECK(a==b(2,1));
}

TEST_CASE("Test 2. Przeciazenie operatora porownania '!=' ")
{
    Vector int a(1.0000000001,2.0000000001),b;
    CHECK_FALSE(a==b(1,2));
    CHECK(a==b(1.00000003,1.99999999));
}

TEST_CASE("Test: Przeciazenie operatora dodawania")
{
    Vector int a(1,1),b(1,2),c;
    CHECK(a+b==c(2,3));
    CHECK_FALSE(a+b==c(2,2));

    Vector double a(1.0000000001,2.0000000001),b(1,2),c;
    CHECK(a+b==c(2,4));
    CHECK_FALSE(a+b==c(),-0,99999999));
}

TEST_CASE("Test: Przeciazenie operatora odejmowania")
{
    Vector int a(1,1),b(1,2),c;
    CHECK(a-b==c(0,-1));
    CHECK_FALSE(a-b==c(0,0));

    Vector double a(1.0000000001,2.0000000001),b(1,2),c;
    CHECK(a-b==c(0,-1));
    CHECK_FALSE(a-b==c(0.999999999,-0,99999999));
}

TEST_CASE("Test: Przeciazenie operatora mnozenia")
{
    Vector int a(1,1),b(2,0),c;
    CHECK(a*b==c(2,2));
    CHECK_FALSE(a*b==c(2,0));

    Vector double a(1.0000000001,1.0000000001),b(2,0),c;
    CHECK(a*b==c(2,2));
    CHECK_FALSE(a*b==c(2.00000001,4.00000001));
}

TEST_CASE("Test: Przeciazenie operatora dzielenia")
{
    Vector int a(4,2),b(2,0),c;
    CHECK(a/b==c(2,1));
    CHECK_FALSE(a/b==c(2,0));

    Vector double a(4.0000000001,2.0000000001),b(2,0),c;
    CHECK(a/b==c(2,1));
    CHECK_FALSE(a/b==c(2.00000001,0.000000001));
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

