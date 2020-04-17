//cpp
#include "tic_tac_toe.h"
#include <iostream>

using std::cout; 

bool TicTacToe::game_over()
{
	if (check_column_win() || check_diagonal_win() || check_row_win())
	{
		set_winner();
		return true;
	}
	if (check_board_full())
	{
		winner = "C";
		return true;
	}
	else
	{
		return check_board_full();
	}


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
	if (pegs.size() == 9)
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
		if (game_over() == false)
		{
			set_next_player();
		}
	}
	else if (pegs.size() == 16)
	{
		if (position >= 1 && position <= 16)
		{

		}
		else
		{
			throw Error("Position must be 1 to 16");
		}
		if (player == "")
		{
			throw Error("Must start game first.");
		}

		pegs[position - 1] = player;
		if (game_over() == false)
		{
			set_next_player();
		}
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

bool TicTacToe::check_column_win()
{
	return false;
}

bool TicTacToe::check_row_win()
{
	return false;
}

bool TicTacToe::check_diagonal_win()
{
	
	return false;
}

void TicTacToe::set_winner()
{
	if (player == "X")
	{
		winner = "O";
	}
	else
	{
		winner = "X";
	}
}

void TicTacToe::set_next_player()
{
	if (player == "X")
	{
		next_player = "O";
		player = "O";
	}
	else
	{
		next_player = "X";
		player = "X";
	}
}

void TicTacToe::clear_board()
{
	for (auto &peg : pegs)
	{
		peg = " ";
	}
}

std::istream& operator>>(std::istream& in, TicTacToe& b)
{
	int position{ 0 };
	cout << "\nPlayer " << b.get_player() << " enter a position (1 to 9): ";
	in >> position;
	try
	{
		b.mark_board(position);
	}
	catch (Error e)
	{
		cout << e.get_message() << "\n";
		
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& b)
{
	if (b.pegs.size() == 9)
		for (int i = 0; i < 9; i += 3)
		{
			out << b.pegs[i] << "|" << b.pegs[i + 1] << "|" << b.pegs[i + 2] << "\n";

		}
	else if (b.pegs.size() == 16)
		for (int i = 0; i < 16; i += 4)
		{
			out << b.pegs[i] << "|" << b.pegs[i + 1] << "|" << b.pegs[i + 2] << "|" << b.pegs[i + 3] << "\n";

		}
	return out;
	
}
