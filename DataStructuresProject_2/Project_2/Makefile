hepsi: derle calistir

derle: AvlNode AvlTree Main List Node Stack
	g++ ./lib/AvlNode.o ./lib/AvlTree.o ./lib/main.o ./lib/List.o ./lib/Node.o ./lib/Stack.o -o ./bin/program

AvlNode:
	g++ -I "./include" -c ./src/AvlNode.cpp -o ./lib/AvlNode.o
AvlTree:
	g++ -I "./include" -c ./src/AvlTree.cpp -o ./lib/AvlTree.o
Main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
List:
	g++ -I "./include" -c ./src/List.cpp -o ./lib/List.o
Node:
	g++ -I "./include" -c ./src/Node.cpp -o ./lib/Node.o
Stack:
	g++ -I "./include" -c ./src/Stack.cpp -o ./lib/Stack.o
textDosyasi:
	./bin/program.exe text.txt
calistir:
	./bin/program.exe