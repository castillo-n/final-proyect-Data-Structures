cmake_minimum_required(VERSION 3.3)
project(FinalProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Seat.cpp Seat.h Economy.cpp Economy.h EconomyPlus.cpp Economy.h FirstClass.cpp FirstClass.h Plane.cpp Plane.h Flight.cpp Flight.h Passenger.cpp Passenger.h Itinerary.cpp Itinerary.h)
add_executable(FinalProject ${SOURCE_FILES})