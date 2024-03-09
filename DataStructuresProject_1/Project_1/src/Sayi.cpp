/*
 * Sayi.cpp
 * Basamak dugumlerini barındıran ve islemler yapan liste
 * 1.Ogretim B gurubu
 * 1. Odev
 * 26.11.2023
 * Uğur Can Çelik, ugur.celik16@ogr.sakarya.edu.tr
 */
#include "Sayi.hpp"

Sayi::Sayi()
{
    ilk = 0;
}

Sayi::~Sayi()
{
    dugumleriSil();
}

void Sayi::dugumleriSil()
{
    Basamak *sil = ilk;

    while (sil != nullptr)
    {
        Basamak *sonraki = sil->sonraki;
        delete sil;
        sil = sonraki;
    }
    ilk = nullptr;
};

void Sayi::basamakTersle()
{
    Basamak *ptrSonraki = NULL;
    Basamak *ptrOnceki = NULL;
    Basamak *ptrIlk = ilk;

    while (ptrIlk != 0)
    {
        ptrSonraki = ptrIlk->sonraki;
        ptrIlk->sonraki = ptrOnceki;
        ptrOnceki = ptrIlk;
        ptrIlk = ptrSonraki;
    }

    ilk = ptrOnceki;
}

void Sayi::ekle(int veri)
{
    Basamak *yeni = new Basamak(veri);

    if (ilk == 0)
    {
        ilk = yeni;
        return;
    }

    Basamak *gec = ilk;

    while (gec->sonraki != 0)
    {
        gec = gec->sonraki;
    }

    gec->sonraki = yeni;
}

void Sayi::basaEkle(Basamak *eklenecekDugum)
{
    if (ilk == NULL)
    {
        ilk = eklenecekDugum;
    }
    else
    {
        Basamak *gecici = ilk;
        ilk = eklenecekDugum;
        ilk->sonraki = gecici;
    }
}

int Sayi::basamakSayisi() const
{
    Basamak *basamak = ilk;
    int basamakSayisi = 0;

    while (basamak != 0)
    {
        basamakSayisi++;
        basamak = basamak->sonraki;
    }

    return basamakSayisi;
}

string Sayi::sayiYaz() const
{
    string sayi;
    Basamak *basamak = ilk;

    while (basamak != 0)
    {
        sayi += (char)basamak->veri + 48;
        basamak = basamak->sonraki;
    }

    return sayi;
}

void Sayi::tekleriBasaAl()
{
    if (ilk == NULL)
    {
        return;
    }

    Basamak *temp = ilk;
    Basamak *ptrKonum = ilk;

    while (ptrKonum != NULL)
    {

        if (ptrKonum->sonraki == NULL)
        {
            break;
        }
        else if (ptrKonum->sonraki->sonraki == NULL && ptrKonum->sonraki->veri % 2 == 1)
        {
            Basamak *gecici = ptrKonum;
            basaEkle(ptrKonum->sonraki);
            ptrKonum->sonraki = NULL;
        }
        else if (ptrKonum->sonraki->veri % 2 == 0)
        {
            ptrKonum = ptrKonum->sonraki;
        }
        else
        {
            Basamak *basaEklenecekEleman = ptrKonum->sonraki;
            Basamak *baglanacakEleman = basaEklenecekEleman->sonraki;

            ptrKonum->sonraki = baglanacakEleman;
            basaEkle(basaEklenecekEleman);
        }
    }
}