#include<iostream>

#include<cstdlib>

#include<ctime>


using namespace std;

int main()
 
{
    srand(time(0)); // Seed the random number generator
    int randomNumber = rand() % 100 + 1; // Generate a random number between 1 and 100

    int guess;
    int numberOfGuesses = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;

    do {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;
        numberOfGuesses++;

        if (guess < randomNumber) {
            cout << "Too low! Guess again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high! Guess again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << numberOfGuesses << " guesses!" << endl;
        }
    } while (guess != randomNumber);

    return 0;
}