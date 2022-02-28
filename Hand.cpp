//
// Created by gamer on 2/27/2022.
//
#include "hand.h"
#include <map>
#include <algorithm>


Hand::Hand() {

}

Hand::Hand(Card c) {
    cards.push_back(c);
}

bool Hand::addToHand(Card c) {
    if(cards.size() < HAND_SIZE)
        cards.push_back(c);
    else
        return false;

    return true;
}

bool Hand::isPair() {
/*  char searchItem;

  for(int i = 0; i< cards.size();i++) {
    searchItem = getVal(cards[i]);

    for(int j = i + 1; j < cards.size(); j++) {
      if(searchItem == getVal(cards[j]))
        return true;
    }
  }

  return false; */
    std::map<char,int> counts;

    for(int i = 0; i < cards.size(); i++) {
        char cardVal = getVal(cards[i]);

        if(counts.count(cardVal) < 0)
            counts.at(cardVal) = 1;
        else
            counts.at(cardVal) = counts[cardVal] + 1;
    }

    for (auto it = counts.cbegin(); it != counts.cend(); ++it)
        if((*it).second == 2)
            return true;

    return false;
}

bool Hand::isToK() {
    /* char searchItem;
     int count = 2; //Decrement when a match to the card is found

     for(int i = 0; i< cards.size();i++) {
       searchItem = getVal(cards[i]);

       for(int j = i + 1; j < cards.size(); j++) {
         if(searchItem == getVal(cards[j]))
           count--;
       }
     }

     if(count < 0)  //If there are two matches, it is a ToK
       return true;

     return false; */
    std::map<char,int> counts;

    for(int i = 0; i < cards.size(); i++) {
        char cardVal = getVal(cards[i]);

        if(counts.count(cardVal) < 0)
            counts.at(cardVal) = 1;
        else
            counts.at(cardVal) = counts[cardVal] + 1;
    }

    for (auto it = counts.cbegin(); it != counts.cend(); ++it)
        if((*it).second == 3)
            return true;

    return false;
}

bool Hand::isFoK() { // Not properly working
/*  char searchItem;   //Will give true for a Full House
  int count = 3; //Decrement when a match to the card is found

  for(int i = 0; i< cards.size();i++) {
    searchItem = getVal(cards[i]);

    for(int j = i + 1; j < cards.size(); j++) {
      if(searchItem == getVal(cards[j]))
        count--;
    }
  }

  if(count < 0)  //If there are three matches, it is a FoK
    return true;

  return false;
  */

    std::map<char,int> counts;

    for(int i = 0; i < cards.size(); i++) {
        char cardVal = getVal(cards[i]);

        if(counts.count(cardVal) < 0)
            counts.at(cardVal) = 1;
        else
            counts.at(cardVal) = counts[cardVal] + 1;
    }

    for (auto it = counts.cbegin(); it != counts.cend(); ++it)
        if((*it).second == 4)
            return true;

    return false;
}

bool Hand::isFH() {
    bool pair = false;
    bool three = false;

    std::map<char,int> counts;

    for(int i = 0; i < cards.size(); i++) {
        char cardVal = getVal(cards[i]);

        if(counts.count(cardVal) < 0)
            counts.at(cardVal) = 1;
        else
            counts.at(cardVal) = counts[cardVal] + 1;
    }

    for (auto it = counts.cbegin(); it != counts.cend(); ++it) {
        if((*it).second == 3)
            three = true;
        else if((*it).second == 2)
            pair =true;
    }

    if(pair && three)
        return true;
    else
        return false;

}

bool Hand::isFl() {
    char cardSuit;
    char flushSuit;

    flushSuit = getSuit(cards[0]);

    for(int i = 1; i < cards.size(); i++) {
        cardSuit = getSuit(cards[i]);
        if(cardSuit != flushSuit)
            return false;
    }
    return true;
}

bool Hand::isStr() {
//     int lowestValue;
//     int currentValue
//     4 lowestValue=getVal(cards{0};(int i=1;i < cards.size();i++){
//         currentValue=getVal(cards{i});
//     }
// code excerpt written by Sophie Winterle 2/28/2022

    sortHand();
    for(int i = 0; i < cards.size() - 1; i++) {
        if(i == 3 && (cards[i].get_rank() == 3) && (cards[i+1].get_rank() == 12))
            return true;
        if( (cards[i].get_rank() + 1) != cards[i+1].get_rank())
            return false;
    }

    return true;
}

bool Hand::isRF() {
    if(isSF() && contains(12) && contains(11))
        return true;
    return false;
}

bool Hand::isSF() {
    if(isFl() && isStr())
        return true;
    return false;
}

bool Hand::contains(int rank) {
    for(int i = 0; i < cards.size(); i++) {
        if(cards[i].get_rank() == rank)
            return true;
    }

    return false;
}

void Hand::evaluateHand() {
    uint32_t handInd = 0;
    //if (this->isPair() && !isToK() && !isFoK())
    handInd = 1;

}

char Hand::getVal(Card c) {
    std::string temp = c.Card2Str();
    return temp[1];
}

char Hand::getSuit(Card c) {
    std::string temp = c.Card2Str();
    return temp[0];
}

void Hand::printHand() {
    for(int i = 0; i < cards.size(); i++)
        std::cout << cards[i].Card2Str() << std::endl;
}

void Hand::resetHand() {
    cards.clear();
}

void Hand::sortHand() {
    std::sort(cards.begin(),cards.end());
}

