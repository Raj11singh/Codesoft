#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess = 0;

    cout << "Guess the number (between 1 and 100): ";
    while (guess != number) {
        cin >> guess;

        if (guess < number) {
            cout << "Too low. Try again: ";
        } else if (guess > number) {
            cout << "Too high. Try again: ";
        } else {
            cout << "Congratulations! You guessed the number." << endl;
        }
    }

    return 0;
}
