tp7: tp7.o String.o
	g++ -o tp7 tp7.o String.o
  
tp7.o: tp7.cpp String.h
	g++ -o tp7.o -c tp7.cpp
	
String.o: String.cpp String.h
	g++ -o String.o -c String.cpp
