#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
#include <ctime>

using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    Card compCard, userCard;
    auto nWin = 0, nLoss = 0;
    srand(time(NULL));

    play = true;
    while (play) {
        // assign values to computer and user
        compCard = Card(rand() % 13, rand() % 4);
        userCard = Card(rand() % 13, rand() % 4);

        // show computer card
        compCard.toString();

        invalid = true;
        while (invalid) {
            // get user's bet
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if (compCard < userCard && guessedHigher) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        }
        userCard.toString();

        // ask user to play again
        invalid = true;
        while (invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << " (W-L)" << endl;

    return 0;
}