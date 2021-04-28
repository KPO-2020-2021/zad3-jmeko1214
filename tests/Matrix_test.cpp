#include "../tests/doctest/doctest.h"
#include "matrix.hh"

TEST_CASE("Test 1 operatora porownania '=='")
{
    Matrix A,B;
    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    B(0,0)=1; B(0,1)=2;
    B(1,0)=3; B(1,1)=4;

    CHECK(A==B);
}

TEST_CASE("Test 2 operatora porownania '=='")
{
    Matrix A,B;
    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    B(0,0)=0; B(0,1)=2;
    B(1,0)=3; B(1,1)=4;

    CHECK_FALSE(A==B);
}

TEST_CASE("Test 3 operatora porownania '=='")
{
    Matrix A,B;
    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    B(0,0)=1; B(0,1)=0;
    B(1,0)=3; B(1,1)=4;

    CHECK_FALSE(A==B);
}

TEST_CASE("Test 4 operatora porownania '=='")
{
    Matrix A,B;
    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    B(0,0)=1; B(0,1)=2;
    B(1,0)=0; B(1,1)=4;

    CHECK_FALSE(A==B);
}

TEST_CASE("Test 5 operatora porownania '=='")
{
    Matrix A,B;
    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    B(0,0)=1; B(0,1)=2;
    B(1,0)=3; B(1,1)=0;

    CHECK_FALSE(A==B);
}

TEST_CASE("Test 1 operatora porownania '!='")
{
    Matrix A,B;
    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    B(0,0)=1; B(0,1)=2;
    B(1,0)=3; B(1,1)=0;

    CHECK(A!=B);
}

TEST_CASE("Test 2 operatora porownania '!='")
{
    Matrix A,B;
    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    B(0,0)=1; B(0,1)=2;
    B(1,0)=3; B(1,1)=4;

    CHECK_FALSE(A!=B);
}

TEST_CASE("Test 1 operatora mnozenia")
{
    Vector a,b;
    Matrix A;

    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    a[0]=1; a[1]=2;
    b[0]=5; b[1]=11;

    CHECK((A*a)==b);
}

TEST_CASE("Test 2 operatora mnozenia")
{
    Vector a,b;
    Matrix A;

    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    a[0]=1; a[1]=2;
    b[0]=1; b[1]=2;

    CHECK_FALSE((A*a)==b);
}
