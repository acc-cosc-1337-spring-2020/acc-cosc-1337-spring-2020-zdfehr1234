//cpp
#include "tic_tac_toe.h"
#include <iostream>

using std::cout; 

bool TicTacToe::game_over()
{
	return check_board_full();
}

void TicTacToe::start_game(string first_player)
{
	if (first_player == "X" || first_player == "O")
	{
		player = first_player;

		next_player = first_player;

		clear_board();
	}
	else
	{
		throw Error("Player must be X or O");
	}


}

void TicTacToe::mark_board(int position)
{

	if (position >= 1 && position <= 9)
	{
		
	}
	else
	{
		throw Error("Position must be 1 to 9");
	}
	if (player == "")
	{
		throw Error("Must start game first.");
	}
	
	pegs[position - 1] = player;
	TicTacToe::set_next_player();
	
	
}

void TicTacToe::display_board() const
{
	for (int i = 0; i < 9; i += 3)
	{
		cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << "\n";
	}
}

bool TicTacToe::check_board_full()
{
	for (std::size_t i = 0; i < pegs.size(); i++)
	{
		if (pegs[i] == " ")
		{
			return false;
		}
	}
	return true;
}

void TicTacToe::set_next_player()
{
	if (player == "X")
	{
		next_player = "O";
	}
	else
	{
		next_player = "X";
	}
}

void TicTacToe::clear_board()
{
	for (auto &peg : pegs)
	{
		peg = " ";
	}
}
