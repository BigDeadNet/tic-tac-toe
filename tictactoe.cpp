#include <iostream>
#include <locale>
using namespace std;

void drawBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

void playerMove(char board[3][3], char symbol) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        cout << "Игрок " << symbol << ", введите строку (1-3) и столбец (1-3): ";
        if (!(cin >> row >> col)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка: введите два числа!" << endl;
            continue;
        }

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Ошибка: координаты должны быть от 1 до 3." << endl;
            continue;
        }

        if (board[row - 1][col - 1] != ' ') {
            cout << "Ошибка: эта клетка уже занята!" << endl;
            continue;
        }

        board[row - 1][col - 1] = symbol;
        validMove = true;
    }
}

char checkWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return ' ';
}

int main() {
    setlocale(LC_ALL, ""); // важно для правильного отображения русского текста
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';
    int moves = 0;
    char winner = ' ';

    while (moves < 9 && winner == ' ') {
        drawBoard(board);
        playerMove(board, currentPlayer);
        winner = checkWinner(board);
        if (winner != ' ')
            break;

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        moves++;
    }

    drawBoard(board);

    if (winner != ' ')
        cout << "Победил игрок " << winner << "!" << endl;
    else
        cout << "Ничья!" << endl;

    return 0;
}
