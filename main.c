#include <stdio.h>
#include <stdbool.h>

/*
 0 = 'X'
 1 = 'O'
 2 = No space
*/

int board[9] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
int winningConditions[8][3] = {
    { 0, 1, 2 },
    { 3, 4, 5 },
    { 6, 7, 8 },
    { 0, 3, 6 },
    { 1, 4, 7 },
    { 2, 5, 8 },
    { 0, 4, 8 },
    { 2, 4, 6 }
};
int playerTurn = 0; // X


void printboard() {
    for (int loop = 0; loop < 9; loop++) {
        char s;
        switch(board[loop]) {
            case 0: {
                s = 'X';
                break;
            }
            case 1: {
                s = 'O';
                break;
            }
            case 2: {
                s = '|';
                break;
            };
        };
        if ((loop % 3) == 0) {
            printf("\n");
        };
        printf("%c ", s);
    };
};

void changeTurn() {
    if (playerTurn == 1) {
        playerTurn = 0;
    } else {
        playerTurn = 1;
    };
};

void play() {
    int num;
    char term;
    if (scanf("%d%c", &num, &term) != 2 || term != '\n') {
        puts("ERROR: NOT A NUMBER");
        return;
    };
    if (num < 1 || num > 9) {
        puts("ERROR: NUMBER NOT BETWEEN 1 AND 9");
        play();
        return;
    };
    if (board[num - 1] != 2) {
        puts("SPACE TAKEN");
        play();
        return;
    };
    board[num - 1] = playerTurn;
    bool wins = false;
    int winnerN;

    for (int i = 0; i < 8; i++) {
        int a = board[winningConditions[i][0]];
        int b = board[winningConditions[i][1]];
        int c = board[winningConditions[i][2]];
        if (a == 2|| b == 2 || c == 2) continue;
        if (a == b && b == c) {
            wins = true;
            winnerN = a;
            break;
        };
    };
    bool testB = false;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 2) {
            testB = true;
            break;
        };
    };
    if (testB == false) {
        system("clear");
        printboard();
        puts("\n\nIt was a tie!");
        return;
    };

    if (wins == true) {
        char winner;
        if (winnerN == 0) {
            winner = 'X';
        } else {
            winner = 'O';
        };
        system("clear");
        printboard();
        printf("\n\n%c wins!\n", winner);
        return;
    };

    system("clear");
    printboard();
    changeTurn();
    puts("\nPick a number between 1-9");
    play();
};

int main() {
    system("clear");
    puts("TicTacToe in C\nPlease enter a number between 1-9");
    printboard();
    printf("\n");
    play();
    return 0;
};
