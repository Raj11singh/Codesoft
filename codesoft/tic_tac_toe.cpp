#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard() {
    cout << "Current board state:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--|---|--\n";
    }
    cout << endl;
}

bool checkWin() {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void updateBoard(int move) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == (char)(move + '0')) {
                board[i][j] = currentPlayer;
                return;
            }
        }
    }
}

void resetBoard() {
    char num = '1';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = num++;
        }
    }
}

int main() {
    bool playAgain = true;
    while (playAgain) {
        resetBoard();
        currentPlayer = 'X';
        bool gameEnded = false;

        while (!gameEnded) {
            displayBoard();
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move >= 1 && move <= 9) {
                updateBoard(move);
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameEnded = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "The game is a draw!\n";
                    gameEnded = true;
                } else {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move. Please enter a number between 1 and 9.\n";
            }
        }

        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            playAgain = false;
        }
    }

    cout << "Tic-Tac-Toe game terminated." << endl;
    return 0;
}
