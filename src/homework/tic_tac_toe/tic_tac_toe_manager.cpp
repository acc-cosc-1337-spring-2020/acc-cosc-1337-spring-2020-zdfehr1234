//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(const TicTacToe b)
{
	games.push_back(b);
	update_winner_count(b.get_winner());
}

void TicTacToeManager::get_winner_total(int& o, int& w, int& t)
{
	
	
	
	o_win = o;
	x_win = w;
	ties = t;
}

void TicTacToeManager::update_winner_count(string winner)
{
	if (winner == "X")
	{
		x_win += 1;
	}
	else if (winner == "O")
	{
		o_win += 1;
	}
	else
	{
		ties += 1;
	}
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
	
	int x_win = 0;
	int o_win = 0;
	int ties = 0;
	
	for (auto& game : manager.games)
	{
		if (game.get_winner() == "X")
		{
			x_win++;
		}
		else if (game.get_winner() == "O")
		{
			o_win++;
		}
		else if (game.get_winner() == "C")
		{ 
			ties++;
		}
	}
	out << "X win: " << x_win << "\tO win: " << o_win << "\tties: " << ties;
	return out;
}
