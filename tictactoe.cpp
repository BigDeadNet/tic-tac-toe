#include <iostream>
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

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';
    int moves = 0;

    while (moves < 9) {  // Максимум 9 ходов
        drawBoard(board);
        playerMove(board, currentPlayer);

        // Смена игрока
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        moves++;
    }

    drawBoard(board);
    cout << "Все ходы сделаны. Конец игры (проверка победителя пока не реализована)." << endl;
    return 0;
}