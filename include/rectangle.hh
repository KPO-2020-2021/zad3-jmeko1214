#pragma once

#define WIERZCHOLKI 4

#include "matrix.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>

class Prostokat
{
    Vector wierzcholek[WIERZCHOLKI];

public:
    bool Obrot(double &kat);
    bool Obrot(double &kat, int krotnosc);
    bool Przesuniecie(Vector &wektor);
    void Zapisz_do_pliku(const std::string &NazwaPliku);
};

bool Prostokat::operator==(const Prostokat &prosty);
std::ostream &operator << (std::ostream &strm, const Prostokat &prosty);
//std::ofstream &operator << (std::ofstream &fstrm, const Prostokat &prosty);