#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }
    return 0; // No win
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    current_player = (current_player == 1) ? 2 : 1;
}

void game() {
    current_marker = 'X';
    current_player = 1;
    int player_won;

    for (int i = 0; i < 9; i++) {
        drawBoard();
        int slot;

        cout << "Player " << current_player << "'s turn. Enter your move (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid move. Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "That spot is taken. Try again.\n";
            i--;
            continue;
        }

        player_won = checkWin();

        if (player_won == 1) {
            cout << "Player 1 wins!\n";
            break;
        } else if (player_won == 2) {
            cout << "Player 2 wins!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (player_won == 0) {
        cout << "It's a draw!\n";
    }
}

int main() {
    char play_again;

    do {
        // Reset the board
        board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
        board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
        board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';

        game();

        cout << "Do you want to play again? (y/n): ";
        cin >> play_again;
    } while (play_again == 'y');

    cout << "Thanks for playing!\n";
    return 0;
}
