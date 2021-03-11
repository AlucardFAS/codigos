from game import input_letter, print_board, get_move, make_move, is_winner, is_board_full, get_computer_move
import random

board = [''] * 10
player_letter, computer_letter = input_letter()

turn = ''
if random.randint(0, 1) == 1: turn = 'computer'
else: turn = 'player'

print(turn +' play first\n')

game_in_progress = True

while game_in_progress:

    if turn == 'player':
        print_board(board)
        move = get_move(board)
        make_move(board, player_letter, move)

        if is_winner(board, player_letter):
            print_board(board)
            print("You win!!")
            game_in_progress = False
        else:
            if is_board_full(board):
                print_board(board)
                print('Draw')
                break
            else:
                turn = 'computer'

    else:
        move = get_computer_move(board, player_letter, computer_letter)
        make_move(board, computer_letter, move)

        if is_winner(board, computer_letter):
            print_board(board)
            print("You lose!!")
            game_in_progress = False

        else:
            if is_board_full(board):
                print_board(board)
                print('Draw')
                break
            else: turn = 'player'