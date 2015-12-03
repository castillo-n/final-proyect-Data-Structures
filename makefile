CXX = g++
CC = g++
FLAGS = -std=c++11

all:		Flight
Seat.o: Seat.cpp Seat.h
	$(CXX) $(FLAGS) -c Seat.cpp
Economy.o: Seat.o Economy.cpp Economy.h
	$(CXX) $(FLAGS) -c Economy.cpp
FirstClass.o: Seat.o FirstClass.cpp firstClass.h  
	$(CXX) $(FLAGS) -c FirstClass.cpp
EconomyPlus.o: Seat.o EconomyPlus.cpp EconomyPlus.h 
	$(CXX) $(FLAGS) -c EconomyPlus.cpp

Flight: main.cpp Economy.o FirstClass.o EconomyPlus.o Flight.cpp Flight.h Itinerary.cpp Itinerary.h Passenger.cpp Passenger.h Plane.cpp Plane.h Seat.cpp Seat.h
	$(CXX) $(FLAGS) -c main.cpp  -o Flight

clobber:
	rm -f *.o *.exe core Flight
