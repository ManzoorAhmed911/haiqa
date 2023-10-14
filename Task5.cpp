#include <iostream>
using namespace std;

char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
char currentPlayer = 'X';
int moves = 0;

// Function to draw the Tic-Tac-Toe board
void drawBoard() {
    cout << "Tic-Tac-Toe" << endl << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if the game is over (win or draw)
bool isGameOver() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return true;

    // Check for a draw
    if (moves == 9)
        return true;

    return false;
}

// Function to make a move
void makeMove() {
    int row, col;
    cout << "Player " << currentPlayer << ", enter row (0, 1, or 2) and column (0, 1, or 2): ";
    cin >> row >> col;

    // Validate the input
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        cout << "Invalid move. Please try again." << endl;
    }
    else {
        board[row][col] = currentPlayer;
        moves++;
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
    }
}

int main() {
    while (!isGameOver()) {
        drawBoard();
        makeMove();
    }

    drawBoard();
    if (isGameOver() && moves < 9) {
        if (currentPlayer == 'X') {
            cout << "Player O wins!" << endl;
        }
        else {
            cout << "Player X wins!" << endl;
        }
    }
    else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
