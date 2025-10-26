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

// Функция безопасного ввода координат
void playerMove(char board[3][3], char symbol) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        cout << "Введите строку (1-3) и столбец (1-3) для хода: ";
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

    drawBoard(board);

    // Один ход крестика
    playerMove(board, 'X');
    drawBoard(board);

    // Один ход нолика
    playerMove(board, 'O');
    drawBoard(board);

    cout << "Ходы завершены (демонстрация работы проверки ввода)." << endl;
    return 0;
}