/*
* main.cpp
* ostream ve menu islemleri
* 1.Ogretim B gurubu
* 1. Odev
* 26.11.2023
* Uğur Can Çelik, ugur.celik16@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>
#include "SayilarListesi.hpp"
#include "Sayi.hpp"
using namespace std;

ostream &operator<<(ostream &os, const Sayi &bl);
ostream &operator<<(ostream &os, const SayilarListesi &sl);

int main()
{
    SayilarListesi sayiListesi;

    char secenek;

    cout << sayiListesi << endl;

    while (true)
    {
        cout << "1) Tek sayilari basa al" << endl;
        cout << "2) Basamaklari tersle" << endl;
        cout << "3) En buyuk sayiyi cikar" << endl;
        cout << "4) Programdan cik" << endl;

        cin >> secenek;

        switch (secenek)
        {
        case '1':
            sayiListesi.tekleriBasaAl();
            cout << sayiListesi << endl;
            break;
        case '2':
            sayiListesi.basamakTersle();
            cout << sayiListesi << endl;
            break;
        case '3':
            sayiListesi.enBuyuguCikar();
            cout << sayiListesi << endl;
            break;
        case '4':
            return 0;
            break;        
        default:
            cout << "\nDuzgun bir secimle yeniden deneyiniz: "<< endl;
            break;
        }
    }
}

ostream& operator  << (ostream& os, const Sayi& sayi)
{
    Basamak* basamak = sayi.ilk;

    int nbasamak = 16;
    string line = "####################";


    if (sayi.basamakSayisi() > nbasamak)
    {
        nbasamak = sayi.basamakSayisi();
        line = "";

        for (int i = 0; i < sayi.basamakSayisi() + 4; i++)
        {
            line += '#';
        }
    }

    os << line << setw(4) << " ";;

    while (basamak != 0)
    {
        os << "***** ";
        basamak = basamak->sonraki;
    }

    basamak = sayi.ilk;

    os << endl;

    os << right << "# " << setw(nbasamak) << &sayi << " #" << setw(4) << " ";
    
    while (basamak != 0)
    {
        os << right << "*" << setw(3) << basamak->sonUcBasamakDondur() << "* ";
        basamak = basamak->sonraki;
    }

    basamak = sayi.ilk;

    os << endl;
    os << line << setw(4) << " ";;

    while (basamak != 0)
    {
        os << "***** ";
        basamak = basamak->sonraki;
    }

    os << endl;

    os << right << "# " << setw(nbasamak) << sayi.sayiYaz() << " #" << setw(4) << " ";

    basamak = sayi.ilk;

    while (basamak != 0)
    {
        os << right << "*" << setw(3)<< basamak->veri << "* ";
        basamak = basamak->sonraki;
    }

    basamak = sayi.ilk;

    os << endl;
    os << line << setw(4) << " ";

    while (basamak != 0)
    {
        os << "***** ";
        basamak = basamak->sonraki;
    }

    return os;
}

ostream &operator<<(ostream &os, const SayilarListesi &sayiListesi)
{
    if (sayiListesi.ilk == 0)
    {
        return os;
    }

    Dugum *sayDugum = sayiListesi.ilk;

    while (sayDugum != 0)
    {

        os << *(sayDugum->veri) << endl
           << endl;

        sayDugum = sayDugum->sonraki;
    }

    return os;
}
