# PokerHandSim
This is a program I designed to get statistical data on poker hands through simulation. It uses several classes to model the behavior of a standard deck of 52 playing cards. Inside the "main.cpp" the settings for test can be changed to conduxt different tests. Tests for specific hands can be found in the 'hand.cpp' class. 
First a Deck object is instantiated and functions within it are used to create a Hand object. From this Hand object, functions that will identify the highest possible hand can be called as well as functions to test for each of the standard individual hands in 5-card poker. 

Improvements could be made to the efficiency that the hands are evaluated. Some work in the hand evaluation function has made it slightly more efficient, but many of the individual functions operate with a very brute-force method. 

The most hands I have simulated at once (a parameter that can be changed in the main file) was 100 million. This simulation took around 2.5 hours. 
