#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS };

// Function to get the computer's choice
Choice getComputerChoice() {
    int randomNum = rand() % 3;
    return static_cast<Choice>(randomNum);
}

// Function to get the user's choice
Choice getUserChoice() {
    int choice;
    cout << "Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ";
    cin >> choice;
    return static_cast<Choice>(choice);
}

// Function to determine the winner
void determineWinner(Choice user, Choice computer) {
    cout << "You chose ";
    switch (user) {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
    }

    cout << ". Computer chose ";
    switch (computer) {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
    }

    cout << endl;

    // Determine the winner
    if (user == computer) {
        cout << "It's a tie!" << endl;
    } else if ((user == ROCK && computer == SCISSORS) ||
               (user == PAPER && computer == ROCK) ||
               (user == SCISSORS && computer == PAPER)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation

    cout << "Welcome to Rock, Paper, Scissors game!" << endl;

    while (true) {
        Choice userChoice = getUserChoice();
        Choice computerChoice = getComputerChoice();

        determineWinner(userChoice, computerChoice);

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}
