//  RANDOM GUESSING GAME CREATED BY C++ LANGUAGE  
// 1 GAME  HAS 3  TRIALS ENJOY IT 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void newgame();
int randnum();
int guessnum();

int main() {
    newgame();
    return 0;
}

void newgame() {
    int totaltrials = 0;
    int totalwins = 0;
    int totallosses = 0;
    int random, guess, trials = 3;
    int gameCount = 1; 

    cout << "-----------------------------------------------------------\n";
    cout << "\t\tWelcome to the Random Number Guessing Game\n";
    cout << "-----------------------------------------------------------\n";

    while (true) {
        random = randnum();
        int attemptsLeft = trials; 

        while (attemptsLeft > 0) {
            guess = guessnum();
            cout << "\n\t The random number is: " << random << endl;
            cout << "\t Your guess number is: " << guess << endl;
            totaltrials++;
            attemptsLeft--;

            if (random == guess) {
                cout << "\nCongratulations!! You're a winner!\n";
                totalwins++;
                break; 
            } else {
                cout << "\nSorry! You lost the game. " << attemptsLeft << " trials left.\n";
                totallosses++;
                if (attemptsLeft > 0) {
                    cout << "Let's try again!\n";
                } else {
                    cout << "The correct number was: " << random << endl;
                }
            }
    }
        
        char choice;
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> choice;
        if (choice != 'Y' && choice != 'y') {
            break; 
        }

        gameCount++;

    }

 
    cout << "--------------------------------------------------------------------\n";
    cout << "\t\t\tGame Over\n\n";
    cout << "\t\t\tTotal Games Played: " << gameCount << "\n";
    cout << "\t\t\tTotal Trials: " << totaltrials << "\n";
    cout << "\t\t\tTotal Wins: " << totalwins << "\n";
    cout << "\t\t\tTotal Losses: " << totallosses << "\n";
    cout << "--------------------------------------------------------------------\n";
}

int randnum() {
    srand(static_cast<unsigned int>(time(nullptr)));
    return rand() % 10;
}

int guessnum() {
    int x;
    cout << "\tGuess the number (between 0 and 9): ";
    cin >> x;
    return x;
}
