/*
* Basamak.cpp
* Sayi listesini dugumu, veri olarak int tutuyor
* 1.Ogretim B gurubu
* 1. Odev
* 26.11.2023
* Uğur Can Çelik, ugur.celik16@ogr.sakarya.edu.tr
*/
#include "Basamak.hpp"
#include <iostream>

Basamak::Basamak(int veri)
{
	this->veri = veri;
	sonraki = NULL;
}

Basamak::~Basamak()
{

}

string Basamak::sonUcBasamakDondur()
{
    stringstream stream;
    
    stream << hex << this;

    string pointerStr = stream.str();

    string sonUcKarakterler = pointerStr.substr(pointerStr.length() - 3);

    return sonUcKarakterler;
}

