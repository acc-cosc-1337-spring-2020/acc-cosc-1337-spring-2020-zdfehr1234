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

bool TicTacToe::check_column_win()
{
	if ((pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X")||(pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O"))
	{
		return true;
	}
	else if ((pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X") || (pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O"))
	{
		return true;
	}
	else if ((pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X") || (pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TicTacToe::check_row_win()
{
	if ((pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X") || (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O"))
	{
		return true;
	}
	else if ((pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X") || (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O"))
	{
		return true;
	}
	else if ((pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X") || (pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TicTacToe::check_diagonal_win()
{
	if ((pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X") || (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O"))
	{
		return true;
	}
	else if ((pegs[2] == "X" && pegs[4] == "X" && pegs[6] == "X") || (pegs[2] == "O" && pegs[4] == "O" && pegs[6] == "O"))
	{
		return true;
	}
	else
	{
		return false;
	}
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
	for (int i = 0; i < 9; i += 3)
	{
		out << b.pegs[i] << "|" << b.pegs[i + 1] << "|" << b.pegs[i + 2] << "\n";
	}
	return out;
	
}
