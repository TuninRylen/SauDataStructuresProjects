#ifndef BASAMAK_hpp
#define BASAMAK_hpp
#include <sstream>
#include <string>

using namespace std;

class Basamak
{
public:
	Basamak(int basamak);
	~Basamak();
	string sonUcBasamakDondur();
	int veri;
	Basamak* sonraki;
};


#endif