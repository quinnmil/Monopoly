SOURCES = player.cpp property.cpp propertytype.cpp game.cpp boardSpace.cpp board.cpp testMonopoly.cpp
HEADERS = player.hpp property.hpp propertytype.hpp game.hpp boardSpace.hpp board.hpp
CXX = g++
CXXFLAGS =  -g -std=c++14

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: Monopoly.exe

Monopoly.exe: propertytype.o property.o player.o boardSpace.o game.o board.o testMonopoly.o
	$(CXX) -o $@ $^

clean:
	$(RM) *.o *.exe
