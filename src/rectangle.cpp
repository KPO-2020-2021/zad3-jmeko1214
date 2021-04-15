#include "rectangle.hh"


bool Prostokat::Obrot(double &kat))
{
    Obrot = this->Obrot(kat, 1);
    return Obrot;
}

bool Prostokat::Obrot(double &kat, int krotnosc)  //krotnosc > ile razy powtorzyc obrot o dany kat
{
    Matrix macierz_obrot; //macierz obrotu
    macierz_obrot.obrot_o_kat(kat);
    for(int i=0; i<krotnosc; i++)
    {
        for(int j=0; j<; j++)
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

bool Prostokat::Zapisz_do_pliku(const std::string &NazwaPliku) const
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


bool Prostokat::operator==(const Prostokat &prosty) const
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        if(this->wierzcholek[i] != prosty.wierzcholek[x])
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

std::ostream &operator << (std::ostream &strm, const Prostokat &prosty)
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        strm << prosty.wierzcholek[i] << std::endl;
    }
    return strm;
}

//std::ofstream &operator << (std::ofstream &fstrm, const Prostokat &prosty)