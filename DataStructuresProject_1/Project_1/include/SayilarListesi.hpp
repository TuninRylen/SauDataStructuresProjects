#ifndef SAYILARLISTESI_hpp
#define SAYILARLISTESI_hpp
#include "Dugum.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

class SayilarListesi
{
public:
	SayilarListesi();
	~SayilarListesi();
	void tekleriBasaAl();
	void basamakTersle();
	void enBuyuguCikar();
	void ekle(Sayi* sayi);
	Sayi* enBuyukSayi();
	Dugum* ilk;

private:
	void txtdenDoldur();
};

#endif 