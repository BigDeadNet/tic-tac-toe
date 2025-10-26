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

// ������� ����������� ����� ���������
void playerMove(char board[3][3], char symbol) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        cout << "������� ������ (1-3) � ������� (1-3) ��� ����: ";
        if (!(cin >> row >> col)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "������: ������� ��� �����!" << endl;
            continue;
        }

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "������: ���������� ������ ���� �� 1 �� 3." << endl;
            continue;
        }

        if (board[row - 1][col - 1] != ' ') {
            cout << "������: ��� ������ ��� ������!" << endl;
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

    // ���� ��� ��������
    playerMove(board, 'X');
    drawBoard(board);

    // ���� ��� ������
    playerMove(board, 'O');
    drawBoard(board);

    cout << "���� ��������� (������������ ������ �������� �����)." << endl;
    return 0;
}