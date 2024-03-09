/*
* SayilarListesi.cpp
* Sayi listesini barındıran ve islemler yapan liste
* 1.Ogretim B gurubu
* 1. Odev
* 26.11.2023
* Uğur Can Çelik, ugur.celik16@ogr.sakarya.edu.tr
*/
#include "SayilarListesi.hpp"
#include "Sayi.hpp"
using namespace std;

SayilarListesi::SayilarListesi()
{
    ilk = 0;
    txtdenDoldur();
}

SayilarListesi::~SayilarListesi()
{
    Dugum *sil = ilk;

    while (sil != nullptr)
    {
        Dugum *sonraki = sil->sonraki;
        delete sil;
        sil = sonraki;
    }
    ilk = nullptr;
}

void SayilarListesi::tekleriBasaAl()
{
    Dugum* gec = this->ilk;

    while (gec != 0) {
        gec->veri->tekleriBasaAl();
        gec = gec->sonraki;
    }
}

void SayilarListesi::basamakTersle()
{
    Dugum* gec = this->ilk;

    while (gec != 0) {
        gec->veri->basamakTersle();
        gec = gec->sonraki;
    }
}

Sayi* SayilarListesi::enBuyukSayi()
{

    Dugum* dugum = ilk;
    Sayi* enBuyukSayi = dugum->veri;

    while (dugum->sonraki != 0)
    {
        if(enBuyukSayi->basamakSayisi() < dugum->sonraki->veri->basamakSayisi())
        {
            enBuyukSayi = dugum->sonraki->veri;
        }
        else if(enBuyukSayi->basamakSayisi() == dugum->sonraki->veri->basamakSayisi())
        {
            Basamak* basamak = dugum->sonraki->veri->ilk;
            Basamak* enBuyuk = enBuyukSayi->ilk;

            while (basamak != 0 && enBuyuk != 0)
            {

                if(basamak->veri > enBuyuk->veri)
                {
                    enBuyukSayi = dugum->sonraki->veri;
                    break;
                }

                enBuyuk = enBuyuk->sonraki;
                basamak = basamak->sonraki;
            }
        }

        dugum = dugum->sonraki;
    }

    return enBuyukSayi;
}

void SayilarListesi::ekle(Sayi* sayi)
{
    Dugum* yeni = new Dugum(sayi);

    if (ilk == 0) {
        ilk = yeni;
        return;
    }

    Dugum* gec = ilk;

    while (gec->sonraki != 0) {
        gec = gec->sonraki;
    }

    gec->sonraki = yeni;
}


void SayilarListesi::enBuyuguCikar()
{
    if (ilk == 0) 
    {
        return;
    }

    Dugum *sayiDugumu = ilk;
    Dugum *onceki = nullptr;
    Sayi* enBuyuk = enBuyukSayi();

    while (sayiDugumu != 0)
    {
        if (sayiDugumu->veri == enBuyuk)
        {
            if (onceki == nullptr) {
                ilk = sayiDugumu->sonraki;
            }
            else {
                onceki->sonraki = sayiDugumu->sonraki;
            }

            delete sayiDugumu;
            break;
        }

        onceki = sayiDugumu;
        sayiDugumu = sayiDugumu->sonraki;
    }
}

void SayilarListesi::txtdenDoldur()
{
    ifstream okumaDosyasi;

    okumaDosyasi.open("text.txt");

    char basamak;

    Sayi* basamakListesi = new Sayi();

    if (okumaDosyasi.is_open()) 
    {

        while (okumaDosyasi.get(basamak))
        {
            if (basamak == ' '|| basamak == '\n')
            {
                if (basamak == ' ')
                {
                    this->ekle(basamakListesi);
                    basamakListesi = new Sayi();
                }
                else 
                {
                    this->ekle(basamakListesi);
                }
            }
            else
            {
                int basamakInt = (int)basamak - 48;
                basamakListesi->ekle(basamakInt);
            }
        }

        this->ekle(basamakListesi);
        okumaDosyasi.close();
    }
}
