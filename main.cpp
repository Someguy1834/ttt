#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <algorithm>

/* Keys:
    0: Space
    1: X
    2: O
*/

enum playerNames {
    NO_PLAYER,
    PLAYER1,
    PLAYER2,
};
char player[3] = {
    '|',
    'X',
    'O',
};
int board[9] = { NO_PLAYER };
int playerTurn = 0;
bool is_number(const std::string& s);
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


void sayPlayer() {
    printf("It is %c's turn\n", player[playerTurn + 1]);
};

void printboard() {
    for (int i = 1; i < 10; i++) {
        printf("%c ", player[board[i - 1]]);
        if ((i % 3) == 0) {
            puts("");
        };
    };
};

void switchplayer() {
    playerTurn = !playerTurn;
};

bool is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(),
    s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
};

int getPlace(){
    std::string input = "";
    input.reserve(2);
    int req = 0;
    while(true) {
        while (!is_number(input)) {
            input.clear();
            std::cin >> input;
        };

        req = std::stoi(input);

        if (req > 0 && req <= 9) {
            if (board[req - 1] != 0) {
                puts("ERROR: SPACE TAKEN");
                input.clear();
                std::cin >> input;
            } else {
                return req;
            };
        } else {
            puts("ERROR: NUMBER NOT BETWEEN 1-9");
            input.clear();
            std::cin >> input;
        };
    };
};

void play() {
    while(true) {
        int req = getPlace();
        int winner = 11;
        board[req - 1] = playerTurn + 1;
        for (int i = 0; i < 8; i++) {
            int a = board[winningConditions[i][0]];
            int b = board[winningConditions[i][1]];
            int c = board[winningConditions[i][2]];
            if (a == b && b == c) {
                if (a == 0) continue;
                winner = a;
                break;
            };
        };

        if (winner != 11) {
            system("clear");
            printboard();
            printf("%c won!\n\n", player[playerTurn + 1]);
            return;
        };

        bool tie = true;
        for (int i = 0; i < 9; i++) {
            if (board[i] == 0) {
                tie = false;
                break;
            };
        };

        if (tie == true) {
            system("clear");
            printboard();
            printf("It was a tie!\n\n");
            return;
        };

        system("clear");
        printboard();
        switchplayer();
        sayPlayer();
    };
};

int main() {
    system("clear");
    puts("TicTacToe in C++\nPlease pick a number between 1-9.");
    sayPlayer();
    printboard();
    play();
    return 0;
};