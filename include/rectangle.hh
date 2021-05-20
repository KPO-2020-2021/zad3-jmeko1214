#pragma once

#define WIERZCHOLKI 4

#include "matrix.hh"
#include "vector.hh"
#include <iostream>                                                                                                                                                                                                                                                                                                                                         
#include <cstdlib>
#include <iomanip>
#include <fstream>

class Prostokat
{
    Vector wierzcholek[WIERZCHOLKI];
    //zaprzyjaznienie funkcji by moc wyswietlac wspolrzedne wierzcholkow
    friend std::ostream & operator << (std::ostream &strm, const Prostokat &prosty);

public:
    bool Obrot(double &kat);                    //metoda odpowiada za obrot prostokota o dany kat                                                                                                                                                                                                                                                                                
    bool Obrot(double &kat, int krotnosc);      //metoda odpowiada o obrot o dany kat okreslona ilosc razy

    bool Przesuniecie(const Vector &wektor);
    bool Wczytaj_z_pliku(const std::string &NazwaPliku);
    bool Zapisz_do_pliku(const std::string &NazwaPliku);
    void Boki() const;                          //sprawdza dlugosci poszczegolnych bokow

    Vector & operator [] (int index);           //przeciazenie operatora indeksowania, sluzy do odczytu i zapisu wierzcholkow
    bool operator == (const Prostokat &prosty) const;
    bool operator != (const Prostokat &prosty) const;
};
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
std::ostream & operator << (std::ostream &strm, const Prostokat &prosty);      //wyswietla wspolrzedne wierzcholkow  


/******************************************************************************
 |  Metoda klasy Prostokat.                                                   |
 |  Argumenty:                                                                |
 |     kat - zmienna przechowujaca wartosc kata w stopniach                   |
 |  Zwraca:                                                                   |
 |     obrot o zadany kat                                                     |
 */
bool Prostokat::Obrot(double &kat)
{
    double obrot;
    obrot = this->Obrot(kat, 1);
    return obrot;
}

/******************************************************************************
 |  Metoda klasy Prostokat.                                                   |
 |  Argumenty:                                                                |
 |     kat - zmienna przechowujaca wartosc kata w stopniach                   |
 |     krotnosc - zmienna przechowujaca liczbe obrotow o zadany kat           |
 |  Zwraca:                                                                   |
 |     Wartosc True                                                           |
 */
bool Prostokat::Obrot(double &kat, int krotnosc)  //krotnosc > ile razy powtorzyc obrot o dany kat
{
    Matrix macierz_obrot; //macierz obrotu
    macierz_obrot.MacierzObrotu(kat);
    for(int i=0; i<krotnosc; i++)
    {
        for(int j=0; j<WIERZCHOLKI; j++)
        {
            wierzcholek[j]=macierz_obrot*wierzcholek[j];
        }
    }
    return true;
}

/******************************************************************************
 |  Realizuje przesuniecie wierzcholkow prostokata o zadany wektor            |                                               
 |  Argumenty:                                                                |
 |     wektor - przechowuje wspolrzedne wektora przesuniecia                  |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostokat::Przesuniecie(const Vector &wektor)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
{
    if(wektor[0]==0 || wektor[1]==0)
    {
        return false;
    }
    else
    {
        for(int i=0; i<WIERZCHOLKI; i++)
        {
            wierzcholek[i] = wierzcholek[i] + wektor;
        }
    }
    return true;
}

/******************************************************************************
 |  Realizuje wczytanie wspolrzednych prostokata z pliku                      |                                               
 |  Argumenty:                                                                |
 |     NazwaPliku - przechowuje nazwe pliku                                   |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostokat::Wczytaj_z_pliku(const std::string &NazwaPliku) 
{
    std::fstream plik;
    Vector PowtorzonyPunkt;    //ostatni wierzcholek prostokata, powtorzony dla zamkniecia rysowania
    plik.open(NazwaPliku);
    if(plik.is_open()==false)
    {
        return false;
    }
    else if(plik.is_open()==true)
    {
        for(int i=0;i<WIERZCHOLKI;i++)
        {
            plik>>wierzcholek[i];
            if(plik.fail())
            {
                plik.close();
                return false;
            }
        }
    }
    plik>>PowtorzonyPunkt;    //pobieranie powtorzonego (ostatniego) punktu i sprawdzenie czy jest on rowny punktowi pierwszemu
    if(plik.fail()||(wierzcholek[0]!=PowtorzonyPunkt))
    {
        plik.close();
        return false;
    }
    else
    {
        return true;
    }
    plik.close();
    return true;
}

/******************************************************************************
 |  Realizuje zapis wspolrzednych prostokata do pliku                         |                                               
 |  Argumenty:                                                                |
 |     NazwaPliku - przechowuje nazwe pliku                                   |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostokat::Zapisz_do_pliku(const std::string &NazwaPliku)
{
    std::fstream plik;
    plik.open(NazwaPliku, std::fstream::out);
    if(plik.is_open()==false)
    {
        return false;
    }
    else
    {
        plik << *this;
        plik << this->wierzcholek[0];
        if(plik.fail())
        {
            plik.close();
            return false;
        }
        plik.close();
        return true;
    }
}

/******************************************************************************
 |  Realizuje porownanie dlugosci przeciwleglych bokow prostokata             |                                               
 |  Argumenty:                                                                |
 |     brak                                                                   |
 |  Zwraca:                                                                   |
 |     Informacje o dlugosci bokow oraz czy sa rowne                          |
 */
void Prostokat::Boki() const           //sprawdzenie dlugosci bokow
{
    double dlugosc[WIERZCHOLKI];   //przechowuje dlugosci bokow
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        dlugosc[i]=(wierzcholek[i+1]-wierzcholek[i]).modul();
    }
    dlugosc[WIERZCHOLKI-1]=(wierzcholek[0]-wierzcholek[WIERZCHOLKI-1]).modul();
    //sprawdzenie rownosci dlugosci przeciwleglych bokow prostokata
    if(dlugosc[0]>dlugosc[1])
    {
        //dlugosc[0] i dlugosc[2] ->dluzsze boki
        //sprawdzenie dlugosci dluzszych bokow
        if(dlugosc[0]==dlugosc[2])
        {
            std::cout<<":)  Dluzsze przeciwlegle boki sa sobie rowne."<<std::endl;
        }
        else
        {
            std::cout<<":o  Dluzsze przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        }
        //wyswietlenie dlugosci bokow dluzszych
        std::cout<<"  Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[0]<<std::endl;
        std::cout<<"    Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[2]<<std::endl<<std::endl;
        
        //sprawdzenie dlugosci krotszych bokow
        if(dlugosc[1]==dlugosc[3])
        {
            std::cout<<":)  Krotsze przeciwlegle boki sa sobie rowne."<<std::endl;
        }
        else
        {
            std::cout<<":o  Krotsze przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        }
        //wyswietlenie dlugosci bokow krotszych
        std::cout<<"  Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[1]<<std::endl;
        std::cout<<"    Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[3]<<std::endl;
    }
    else
    {
        //dlugosc[1] i dlugosc[3] ->dluzsze boki
        //sprawdzenie dlugosci dluzszych bokow
        if(dlugosc[1]==dlugosc[3])
        {
            std::cout<<":)  Dluzsze przeciwlegle boki sa sobie rowne."<<std::endl;
        }
        else
        {
            std::cout<<":o  Dluzsze przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        }
        //wyswietlenie dlugosci bokow dluzszych
        std::cout<<"  Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[1]<<std::endl;
        std::cout<<"    Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[3]<<std::endl<<std::endl;
        
        //sprawdzenie dlugosci krotszych bokow
        if(dlugosc[0]==dlugosc[2])
        {
            std::cout<<":)  Krotsze przeciwlegle boki sa sobie rowne."<<std::endl;
        }
        else
        {
            std::cout<<":o  Krotsze przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        }
        //wyswietlenie dlugosci bokow krotszych
        std::cout<<"  Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[0]<<std::endl;
        std::cout<<"    Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[2]<<std::endl;
   }
}

/******************************************************************************
 |  Przeciazenie operatora porownania ==                                      |                                               
 |  Argumenty:                                                                |
 |     prosty - zmienna pomocnicza do operacji na prostokacie                 |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostokat::operator == (const Prostokat &prosty) const
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        if(this->wierzcholek[i] != prosty.wierzcholek[i])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return true;
}

/******************************************************************************
 |  Przeciazenie operatora porownania =!                                      |                                               
 |  Argumenty:                                                                |
 |     prosty - zmienna pomocnicza do operacji na prostokacie                 |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostokat::operator != (const Prostokat &prosty) const
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        if(this->wierzcholek[i] == prosty.wierzcholek[i])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return true;
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |                                               
 |  Argumenty:                                                                |
 |     strm - strumien wyjsciowy                                              |
 |     prosty - zmienna pomocnicza do operacji na prostokacie                 |
 |  Zwraca:                                                                   |
 |     Strumien wyjsciowy                                                     |
 */
std::ostream & operator << (std::ostream &strm, const Prostokat &prosty)
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        strm << prosty.wierzcholek[i] << std::endl;
    }
    return strm;
}

/******************************************************************************
 |  Przeciazenie operatora indeksowania, do odczytu i zapisu wsp. wierzch.    |                  
 |  Argumenty:                                                                |
 |     index - zmienna przechowuje indeks wierzcholka                         |
 |  Zwraca:                                                                   |
 |     Indeks wierzcholka prostokota                                          |
 */
Vector & Prostokat::operator [] (int index)
{
    return wierzcholek[index];
}
 
 
 
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
