import os

#   Keys:
# 0 - X
# 1 - O
# 2 - No one

board = [2, 2, 2, 2, 2, 2, 2, 2, 2]
player_turn = 0 # X
winningConditions = [
    [ 0, 1, 2 ],
    [ 3, 4, 5 ],
    [ 6, 7, 8 ],
    [ 0, 3, 6 ],
    [ 1, 4, 7 ],
    [ 2, 5, 8 ],
    [ 0, 4, 8 ],
    [ 2, 4, 6 ],
]


def print_board():
    i = 1
    while i < 10:
        s = ""
        branch = board[i - 1]
        if branch == 0:
            s = 'X'
        elif branch == 1:
            s = 'O'
        else:
            s = '|'
        print(s, end=" ")
        if i % 3 == 0:
            print("\n", end="")
        i += 1
#


def main():
    os.system("clear")
    print("TicTacToe in Python\nPlease type a number between 1-9.\nIt is X's turn.")
    print_board()
    play()
#


def play():
    pos = input()
    num = 0
    try:
        num = int(pos)
    except:
        print("ERROR: NOT A NUMBER")
        play()
        return

    if num > 9:
        print("ERROR: NUMBER NOT BETWEEN 1-9")
        play()
        return
    elif num < 1:
        print("ERROR: NUMBER NOT BETWEEN 1-9")
        play()
        return
    if board[num - 1] != 2:
        print("ERROR SPACE TAKEN")
        play()
        return

    board[num - 1] = player_turn
    i = 0
    win = False
    while i < 8:
        a = board[winningConditions[i][0]]
        b = board[winningConditions[i][1]]
        c = board[winningConditions[i][2]]
        i += 1
        if a == b & a == c & c == b:
            if a == 2:
                continue
            win = True
            break
        
    if win == True:
        winner = ""
        if player_turn == 0:
            winner = "X"
        else: 
            winner = "O"
        os.system("clear")
        print_board()
        print("The winner is " + winner + "!")
        return

    os.system("clear")
    print_board()
    switch_turns()
    play()
#


def switch_turns():
    global player_turn
    if player_turn == 1:
        player_turn = 0
        print("It is X's turn.")
    else: 
        player_turn = 1
        print("It's O's turn.")
#

main()