OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-sign-compare -std=c++11

#
program.exe: program.o Almacen.o Sala.o Inventari.o
	g++ -o program.exe *.o
#
program.o: program.cc Almacen.cc Sala.cc Inventari.cc
	g++ -c program.cc $(OPCIONS)
#
Almacen.o: Almacen.cc BinTree.hh
	g++ -c Almacen.cc $(OPCIONS)
#
Sala.o: Sala.cc
	g++ -c Sala.cc $(OPCIONS)
#
Inventari.o: Inventari.cc
	g++ -c Inventari.cc $(OPCIONS)


clean:
	rm *.o
	rm *.exe
