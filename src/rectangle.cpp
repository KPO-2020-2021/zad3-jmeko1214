#include "rectangle.hh"


bool Prostokat::Obrot(double &kat))
{
    double obrot;
    obrot = this->Obrot(kat, 1);
    return obrot;
}

bool Prostokat::Obrot(double &kat, int krotnosc)  //krotnosc > ile razy powtorzyc obrot o dany kat
{
    Matrix macierz_obrot; //macierz obrotu
    macierz_obrot.MacierzObrotu(kat);
    for(int i=0; i<krotnosc; i++)
    {f
        for(int j=0; j<WIERZCHOLKI; j++)
        {
            wierzcholek[j]=macierz_obrot*wierzcholek[j];
        }
    }
    return true;
}

bool Prostokat::Przesuniecie(Vector &wektor)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
{
    if(wektor.modul()==0)
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

bool Prostokat::Wczytaj_z_pliku(const std::string &NazwaPliku,Prostokat prosty) const
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

bool Prostokat::Zapisz_do_pliku(const std::string &NazwaPliku, Prostokat prosty) const
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

void Boki() const           //sprawdzenie dlugosci bokow
{
    double dlugosc[WIERZCHOLKI];   //przechowuje dlugosci bokow
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        dlugosc[i]=abs(wierzcholek[i+1]-wierzcholek[i]);
    }
    dlugosc[WIERZCHOLKI-1]=abs(wierzcholek[0]-wierzcholek[WIERZCHOLKI-1]);
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
        std::cout<<"    Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[3]<<std::endl<<std::endl;
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
        std::cout<<"    Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[2]<<std::endl<<std::endl;
    }
}

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
}

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
}

std::ostream &operator << (std::ostream &strm, const Prostokat &prosty)
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        strm << prosty.wierzcholek[i] << std::endl;
    }
    return strm;
}