//
// Created by gamer on 2/27/2022.
//

#ifndef POKERHANDSIMULATOR_HAND_H
#define POKERHANDSIMULATOR_HAND_H

#include <vector>
#include <iostream>
#include "card.h"

const int HAND_SIZE = 5;

class Hand
{
    friend class Card;

public:
    explicit Hand();
    explicit Hand(Card);

    std::vector<Card> cards;

    uint32_t hand; //0 to 10 - corresponds to index of hands array

    const std::string handsInOrder[10] = {"HC","P","TP","ToK","S","F","FH","FoK","SF","RF"};

    int handsCount[10];

    char getVal(Card);
    char getSuit(Card);

    bool addToHand(Card);
    bool contains(int);
    bool isPair();
    bool isToK();
    bool isFoK();
    bool isFH();
    bool isFl();
    bool isStr();
    bool isRF();
    bool isSF();


    void evaluateHand();
    void printHand();
    void resetHand();
    void sortHand();
};

#endif //POKERHANDSIMULATOR_HAND_H
