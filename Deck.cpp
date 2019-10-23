#include "Deck.h"
#include <iostream>
#include <c++/4.8.3/vector>

using namespace std;

Deck::Deck(){
    arraySize = 52;
    cardsLeft = 52;
    cards = new Card[arraySize];
}

Deck::~Deck(){
    delete []cards;
}

Deck::Deck(const Deck& copyDeck){
    arraySize = copyDeck.arraySize;
    cardsLeft = copyDeck.cardsLeft;
    cards = copyDeck.cards;
}

bool Deck::remove(){
    if(0  == cardsLeft){
        return false;
    }
    else{
        cards--;
        cardsLeft--;
    }
}

bool Deck::add(Card C) {
    if(arraySize == cardsLeft){
        return false;
    }
    else{
        cards[cardsLeft] = C;
        cardsLeft++;
    }
}
