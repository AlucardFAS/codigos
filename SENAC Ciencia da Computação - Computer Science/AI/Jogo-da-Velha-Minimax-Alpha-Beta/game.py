import random

def get_board_copy(board):
	new_board = []
	
	for i in board: new_board.append(i)

	return new_board

def print_board(board):
	copy_board = get_board_copy(board)#to print not danify board with numbers

	for i in range(1,10):
		if(board[i] == ''): copy_board[i] = str(i)
		else: copy_board[i] = board[i]
	
	print('\n ' + copy_board[7] + '|' + copy_board[8] + '|' + copy_board[9])
	print(' '+ copy_board[4] + '|' + copy_board[5] + '|' + copy_board[6])
	print(' '+ copy_board[1] + '|' + copy_board[2] + '|' + copy_board[3] + '\n')

def input_letter():
	letter = ''
	print('Do you want to be X or O?')
	
	while not(letter == 'X' or letter == 'O'): letter = input().upper()
	
	#[player,computer]
	if letter == 'X': return ['X','O']
	else: return ['O','X']

def make_move(board, letter, move):
	board[move] = letter

def remove(board, move):
	board[move] = ''

def is_space_free(board, move):
	if(board[move] == ''): return True
	else: return False

#Receive input move
def get_move(board):
	move = ''
	while move not in '1 2 3 4 5 6 7 8 9'.split() or not is_space_free(board, int(move)):
		print('Enter a movement from 1 to 9')
		move = input()

		if(move not in '1 2 3 4 5 6 7 8 9'): print ('INVALID')
		elif(move in '1 2 3 4 5 6 7 8 9'):
			if(not is_space_free(board, int(move))):
				print ('INVALID')

	return int(move)

def is_board_full(board):
	for i in range(1, 10):
		if is_space_free(board, i): return False

	return True

def possible_options(board):
	possible_options = []

	for i in range(1, 10):
		if is_space_free(board, i):
			possible_options.append(i)

	return possible_options

def is_winner(board, possible_winner):
	return((board[7] == possible_winner and board[8] == possible_winner and board[9] == possible_winner) or
		(board[4] == possible_winner and board[5] == possible_winner and board[6] == possible_winner) or
		(board[1] == possible_winner and board[2] == possible_winner and board[3] == possible_winner) or
		(board[7] == possible_winner and board[4] == possible_winner and board[1] == possible_winner) or 
		(board[8] == possible_winner and board[5] == possible_winner and board[2] == possible_winner) or 
		(board[9] == possible_winner and board[6] == possible_winner and board[3] == possible_winner) or 
		(board[7] == possible_winner and board[5] == possible_winner and board[3] == possible_winner) or 
		(board[9] == possible_winner and board[5] == possible_winner and board[1] == possible_winner)) 

def finish_game(board, computer_letter):

	if computer_letter == 'X': player_letter = 'O'
	else: player_letter = 'X'

	if(is_winner(board, computer_letter)) : return 1 #computer win
	elif(is_winner(board, player_letter)) : return -1 #player win
	elif(is_board_full(board)) : return 0 #draw
	else: return None #in progress

def alpha_beta(board, computer_letter, player_letter, turn, alpha, beta):

	if turn == computer_letter: nextTurn = player_letter
	else: nextTurn = computer_letter

	finish = finish_game(board, computer_letter)
	if (finish != None): return finish

	possible = possible_options(board)

	if turn == computer_letter:
		for move in possible:
			make_move(board, turn, move)
			val = alpha_beta(board, computer_letter, player_letter, nextTurn, alpha, beta)
			remove(board, move)
			
			if val > alpha: alpha = val
			if alpha >= beta: return alpha

		return alpha
	else:
		for move in possible:
			make_move(board, turn, move)
			val = alpha_beta(board, computer_letter, player_letter, nextTurn, alpha, beta)
			remove(board, move)

			if val < beta: beta = val
			if alpha >= beta: return beta

		return beta

def check_iminent_move(computer_letter, player_letter, board):
	copy = get_board_copy(board)

	for i in range(0, 9):#if next move win
		if is_space_free(copy, i):
			make_move(copy, computer_letter, i)
			if is_winner(copy, computer_letter): return i
			else: copy[i] = ''

	for i in range(0, 9):#if player win on next move, block player
		if is_space_free(copy, i):
			make_move(copy, player_letter, i)
			if is_winner(copy, player_letter): return i
			else: copy[i] = ''

	return None

def get_computer_move(board, turn, computer_letter):
	alpha = -2
	options = []

	if computer_letter == 'X': player_letter = 'O'
	else: player_letter = 'X'

	iminent_move = check_iminent_move(computer_letter, player_letter, board)
	if iminent_move != None : return iminent_move

	options = possible_options(board)

	for move in options:
		make_move(board, computer_letter, move)
		val = alpha_beta(board, computer_letter, player_letter, player_letter, -2, 2)		
		remove(board, move)

		if val > alpha:
			alpha = val
			options = [move]
		elif val == alpha: options.append(move)

	return random.choice(options)#return one of the best choices