cmake_minimum_required(VERSION 3.3)
project(final_proyect_Data_Structures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Economy.cpp Economy.h FirstClass.cpp FirstClass.h EconomyPlus.cpp EconomyPlus.h Flight.cpp Flight.h Itinerary.cpp Itinerary.h Passenger.cpp Passenger.h Plane.cpp Plane.h Seat.cpp Seat.h)
add_executable(final_proyect_Data_Structures ${SOURCE_FILES})