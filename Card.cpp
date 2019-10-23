#include "Card.h"
#include <iostream>

Card::Card(){
}

Card::Card(int rank,int suit){
    this->rank = rank;
    this->suit = suit;
}

bool Card::operator<(const Card card1) {
    if(this->rank < card1.rank){
        return true;
    }
    else{
        if(this->suit < card1.suit){
            return true;
        }
    }

    return false;
}

void Card::toString(){
    cout<< ranks[rank]+" of "+suits[suit]<<endl;
}