#include <iostream>
using namespace std;

char board[3][3];

 void initialize() {
    for(int i=0; i<3; i++) {
        for(int j=0;j<3; j++) {
            board[i][j] = ' ';
}
}
}

void Display() {
    for(int i=0; i<3;i++) {
        for(int j=0; j<3;j++) {
            cout << board[i][j];
            if (j<2)
                cout << " | ";
        }
        cout << endl;
        if (i <2)
            cout << "---------" << endl;
    }
}

bool Win(char player) {

for (int i=0; i<3; i++) {
    if((board[i][0]==player && board[i][1] == player && board[i][2] == player) ||
    (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
        return true;
        }
    }

if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool Draw() {
    for (int i=0; i< 3; i++) {
        for (int j=0; j<3;j++) {
            if (board[i][j] == ' ') {
            return false;
        }
    }
    }
    return true;
}


char switchPlayer(char current) {
return (current =='X') ? 'O' : 'X';
}

int main() {
    char CurrentPlayer = 'X';
    int row, col;
    bool GameOver = false;
    initialize();

    while (!GameOver) {
        Display();
    cout<<"Player " << CurrentPlayer << ", enter your move (row and column): ";
    cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = CurrentPlayer;
        if (Win(CurrentPlayer)) {
            Display();
            cout << "Player " <<CurrentPlayer << " wins!" << endl;
            GameOver = true;
        } else if (Draw()) {
            Display();
            cout << "The game is a draw !" << endl;
            GameOver = true;
        } else {

        CurrentPlayer = switchPlayer(CurrentPlayer);
    }
    }

    char PlayAgain;
    cout << "Do you want to play again? (Yes/No): ";
    cin >> PlayAgain;

    if (PlayAgain == 'Yes' ) {
        main();
    }
    return 0;
}
