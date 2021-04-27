#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>

class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy
    Matrix();                               // Konstruktor klasy
    //Metody
    void MacierzObrotu(double stopnie);      // tworzy macierz obrotu o kat w stopniach
    //Przeciazenia operatorow
    Vector operator * (Vector tmp);           // Operator mnożenia przez wektor
    Matrix operator + (Matrix tmp);
    double  &operator () (unsigned int row, unsigned int column);
    const double &operator () (unsigned int row, unsigned int column) const;
    bool operator == (const Matrix &matrix) const;
    bool operator != (const Matrix &matrix) const;
};

std::istream &operator>>(std::istream &in, Matrix &mat);
std::ostream &operator<<(std::ostream &out, Matrix const &mat);


/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
Matrix::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}

/******************************************************************************
 |  Realizuje metode obrotu macierzy o kat.                                   |
 |  Argumenty:                                                                |
 |      value - wartosci poszczegolnych pol macierzy                          |
 |  Zwraca:                                                                   |
 |      Macierz obrotu                    |
 */
void Matrix::MacierzObrotu(double stopnie)
{
    double radiany = stopnie*M_PI/180;           //zamienia stopnie na radiany
    //macierz obrotu
    value[0][0]= cos(radiany);
    value[0][1]= sin(radiany);
    value[1][0]=-sin(radiany);
    value[1][1]= cos(radiany);                   
}

/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator * (Vector tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
Matrix Matrix::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora porowanania ==.                                    |
 |  Argumenty:                                                                |
 |      Vektor i wskaźnik na wektor.                                          |
 |  Zwraca:                                                                   |
 |      Wartość True lub False.                                               |
 */
bool operator == (const Matrix &matrix) const
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(this->value[i][j] == matrix.value[i][j])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

/******************************************************************************
 |  Przeciazenie operatora porowanania !=.                                    |
 |  Argumenty:                                                                |
 |      Vektor i wskaźnik na wektor.                                          |
 |  Zwraca:                                                                   |
 |      Wartość True lub False.                                               |
 */
bool operator != (const Matrix &matrix) const
{
    if(Matrix == matrix)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
std::istream &operator>>(std::istream &in, Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << std::setw(15) << std::fixed << std::setprecision(10) << mat(i, j) << " | "; //wyswietlanie macierzy
        }
        std::cout << std::endl;
    }
    return out;
}

