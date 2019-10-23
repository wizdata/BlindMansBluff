#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H
#include<list>
#include "Card.h"


class Deck {
public:
    Deck();
    ~Deck();
    Deck(const Deck& copyDeck);
    //shuffle(Card )
    bool remove();
    bool add(Card);
private:
    int arraySize;
    int cardsLeft;
    Card* cards;
    //list<Card> cards;
};


#endif //BLINDMANSBLUFF_DECK_H
