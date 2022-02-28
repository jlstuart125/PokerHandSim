//
// Created by gamer on 2/27/2022.
//

#ifndef POKERHANDSIMULATOR_DECK_H
#define POKERHANDSIMULATOR_DECK_H

#include <vector>
#include <iostream>
#include <fstream>
#include "card.h"

using namespace std;

class Deck
{
public:
    explicit Deck();
    void print_Deck() const;

    Card getOneCard();
    void shuffleDeck();
    void resetDeck();

private:
    std::vector<Card> m_deck;

};

#endif //POKERHANDSIMULATOR_DECK_H
