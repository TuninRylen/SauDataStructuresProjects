#ifndef DUGUM_hpp
#define DUGUM_hpp
#include "Sayi.hpp"

class Dugum
{
public:
	Dugum(Sayi* sayi);
	~Dugum();

	Sayi* veri;
	Dugum* sonraki;
};


#endif 
