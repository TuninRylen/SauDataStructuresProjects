/*
* Dugum.cpp
* SayilarListesinin dugumu, veri olarak Sayi listesi adresi tutuyor
* 1.Ogretim B gurubu
* 1. Odev
* 26.11.2023
* Uğur Can Çelik, ugur.celik16@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

Dugum::Dugum(Sayi* veri)
{
	this->veri = veri;
	sonraki = NULL;
}

Dugum::~Dugum()
{
	delete this->veri;
}
