DerleVeCalistir: Derle calistir

Derle:Basamak Dugum Sayi SayilarListesi Main
	g++ ./lib/Dugum.o ./lib/Sayi.o ./lib/Basamak.o ./lib/SayilarListesi.o ./lib/Main.o -o ./bin/program

Basamak:
	g++ -I "./include" -c ./src/Basamak.cpp -o ./lib/Basamak.o
Dugum:
	g++ -I "./include" -c ./src/Dugum.cpp -o ./lib/Dugum.o
Sayi:
	g++ -I "./include" -c ./src/Sayi.cpp -o ./lib/Sayi.o
SayilarListesi:
	g++ -I "./include" -c ./src/SayilarListesi.cpp -o ./lib/SayilarListesi.o
Main:
	g++ -I "./include" -c ./src/Main.cpp -o ./lib/Main.o
textDosyasi:
	./bin/program.exe text.txt
calistir: 
	./bin/program.exe