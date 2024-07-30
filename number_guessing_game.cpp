#include <bits/stdc++.h>
using namespace std;

void playGame(int choices, int secretNumber) {
    int playerChoice;
    int choicesLeft = choices;

    for (int i = 1; i <= choices; i++) {
        cout << "\n\nEnter the number: ";
        cin >> playerChoice;

        if (playerChoice == secretNumber) {
            cout << "Well played! You won, " << playerChoice
                 << " is the secret number" << endl;
            cout << "\t\t\tThanks for playing...." << endl;
            cout << "Play the game again with us!!\n\n" << endl;
            return;
        } else {
            cout << "Nope, " << playerChoice << " is not the right number\n";
            if (playerChoice > secretNumber) {
                cout << "The secret number is smaller than the number you have chosen" << endl;
            } else {
                cout << "The secret number is greater than the number you have chosen" << endl;
            }
            choicesLeft--;
            cout << choicesLeft << " choices left." << endl;
            if (choicesLeft == 0) {
                cout << "You couldn't find the secret number, it was " << secretNumber << ", You lose!!\n\n";
                cout << "Play the game again to win!!!\n\n";
                return;
            }
        }
    }
}

int main() {
    cout << "\n\t\t\tWelcome to GuessTheNumber game!" << endl;
    cout << "You have to guess a number between 1 and 100. You'll have limited choices based on the level you choose. Good Luck!" << endl;

    // Seed the random number generator once
    srand(time(0));

    while (true) {
        cout << "\nEnter the difficulty level: \n";
        cout << "1 for easy!\t";
        cout << "2 for medium!\t";
        cout << "3 for difficult!\t";
        cout << "0 for ending the game!\n" << endl;

        // Select the level of difficulty
        int difficultyChoice;
        cout << "Enter the number: ";
        cin >> difficultyChoice;

        // Generating the secret number
        int secretNumber = 1 + (rand() % 100);

        // Difficulty Level Handling
        switch (difficultyChoice) {
            case 1:
                cout << "\nYou have 10 choices for finding the secret number between 1 and 100.";
                playGame(10, secretNumber);
                break;
            case 2:
                cout << "\nYou have 7 choices for finding the secret number between 1 and 100.";
                playGame(7, secretNumber);
                break;
            case 3:
                cout << "\nYou have 5 choices for finding the secret number between 1 and 100.";
                playGame(5, secretNumber);
                break;
            case 0:
                cout << "Thanks for playing! Goodbye!" << endl;
                return 0;
            default:
                cout << "Wrong choice, Enter valid choice to play the game! (0,1,2,3)" << endl;
        }
    }
    return 0;
}