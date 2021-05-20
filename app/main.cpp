// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"
#include "../include/lacze_do_gnuplota.hh"


int main() {
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;

    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);

  double kat;
  int krotnosc;
  Vector wektor;
  Prostokat prosty;
  char opcja;  //zmienna dla obslugi prostego menu

  std::cout<<"\n Program rysuje w gnuplocie prostokat z pliku,"<<std::endl;
  std::cout<<" obraca go o zadany kat i przesuwa o zadany wektor."<<std::endl;
  std::cout<<" Wynik jest wyswietlany w gnuplocie oraz zapisywany do pliku."<<std::endl<<std::endl;
  //wyswietlenie prostego menu
  std::cout<<" Menu programu:"<<std::endl<<std::endl;
  std::cout<<" o - obrot prostokata o zadany kat"<<std::endl;
  std::cout<<" p - przesuniecie prostokata o zadany wektor"<<std::endl;
  std::cout<<" w - wyswietlanie wspolrzednych wierzcholkow"<<std::endl;
  std::cout<<" m - wyswietl menu"<<std::endl;
  std::cout<<" k - koniec dzialania programu"<<std::endl;



  while(opcja!='k')
  {
    if(!prosty.Wczytaj_z_pliku("../datasets/prostokat.dat"))
    {
      std::cerr<<"Blad! Nie udalo sie wczytac pliku ze wspolrzednymi prostokota!"<<std::endl;
      return 1;
    }
    prosty.Boki(); // wyswietla dlugosci bokow z dokladnoscia do 10 miejsc po przecinku
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    std::cout<<std::endl;
    std::cout<<" Twoj wybor? (m - menu) > ";
    std::cin>>opcja;
    std::cout<<std::endl;

    switch(opcja)   //obsluga prostego menu
    {
      case 'o':
      {
        std::cout<<" Podaj wartosc kata obrotu w stopniach"<<std::endl;
        std::cin>>kat;
        std::cout<<" Ile razy operacja obrotu ma byc powtorzona?"<<std::endl;
        std::cin>>krotnosc;
        prosty.Obrot(kat,krotnosc);
        prosty.Zapisz_do_pliku("../datasets/prostokat.dat");
        Lacze.Rysuj();
        prosty.Boki();
        break;
      }
      case 'p':
      {
        std::cout<<" Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb"<<std::endl;
        std::cout<<" tzn. wspolrzednej x oraz wsporzednej y."<<std::endl;
        std::cin>>wektor;
        prosty.Przesuniecie(wektor);
        prosty.Zapisz_do_pliku("../datasets/prostokat.dat");
        Lacze.Rysuj();
        break;
      }
      case 'w':
      {
        std::cout<<std::endl;
        std::cout<<prosty<<std::endl;     //wyswietla nam wspolrzedne wierzcholkow
        break;
      }
      case 'm':
      {
        std::cout<<" Menu programu:"<<std::endl<<std::endl;
        std::cout<<" o - obrot prostokata o zadany kat"<<std::endl;
        std::cout<<" p - przesuniecie prostokata o zadany wektor"<<std::endl;
        std::cout<<" w - wyswietlanie wspolrzednych wierzcholkow"<<std::endl;
        std::cout<<" m - wyswietl menu"<<std::endl;
        std::cout<<" k - koniec dzialania programu"<<std::endl;
        break;
      }
      case 'k':
      {
        std::cout<<"\n Koniec dzialania programu.\n"<<std::endl;
        break;
      }
      default:
      {
        std::cerr<<"\n Blad! Nie rozpoznano opcji menu. Sprobuj jeszcze raz."<<std::endl;
        break;
      }
    }
  }       
  
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
