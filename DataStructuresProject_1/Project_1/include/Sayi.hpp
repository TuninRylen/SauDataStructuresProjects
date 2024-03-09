#ifndef SAYI_hpp
#define SAYI_hpp
#include "Basamak.hpp"
#include <string>
#include <iostream>
using namespace std;

class Sayi
{
public:
	Sayi();
	~Sayi();
	void ekle(int basamak);
	void basamakTersle();
	void tekleriBasaAl();
	void basaEkle(Basamak* basamak);
	int basamakSayisi() const;
	string sayiYaz() const;
	Basamak* ilk;
	
private:
	void dugumleriSil();
};

#endif