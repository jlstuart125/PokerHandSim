cmake_minimum_required(VERSION 3.20)
project (PokerHandSimulator)

set(CMAKE_CXX_STANDARD 23)

add_executable(PokerHandSimulator main.cpp Hand.h Hand.cpp Card.h Card.cpp Deck.h Deck.cpp)
