#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>

#include "card.h"
#include "deck.h"
#include "hand.h"

void dealHand(Hand &, Deck &);
void prepareDeck(Deck &);

const int NUM_TRIALS = 1;

int main()
{
    time_t start,end;
    double timeTaken;

    time(&start); //set the start time
    ios_base::sync_with_stdio(false); //unsysnc time with IO

    Deck _deck;
    Hand hand;

    int count;
    uint64_t total = 0;

    _deck.print_Deck();

    _deck.shuffleDeck();
    //_deck.getOneCard();

    std::cout << std::endl;
    _deck.print_Deck();

    std::cout << std::endl;

    for(int i = 0; i < NUM_TRIALS; i++) {
        count = 0;
        do {

            dealHand(hand,_deck);

            prepareDeck(_deck);

            count++;
        } while(!hand.isRF());

        total += count;
    }

    cout << "Average hands to recieve a Full House is " <<
         (double) total/(double)NUM_TRIALS << endl;

    hand.printHand();

    std::cout << count << std::endl;


    time(&end);

    timeTaken = double(end - start);

    std::cout << "Execution took: " << timeTaken << " seconds" << std::endl;

    return 0;
}

void dealHand(Hand &h, Deck &d) {
    h.resetHand();
    for(int i = 0 ; i < 5; i++)
        h.addToHand(d.getOneCard());
}

void prepareDeck(Deck &d) {
    d.resetDeck();
    d.shuffleDeck();
}