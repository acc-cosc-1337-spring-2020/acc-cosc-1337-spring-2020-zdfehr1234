//cpp
#include "tic_tac_toe_manager.h"

TicTacToeManager::TicTacToeManager(TicTacToeData & data)
{
	//TicTacToeData data;
	data.get_games();
	for (auto &game : games)
	{
		update_winner_count(game->get_winner());
	}
}

TicTacToeManager::~TicTacToeManager()
{
	data.save_games(games);
}

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game)
{
	
	update_winner_count(game->get_winner());
	games.push_back(std::move(game));
}

void TicTacToeManager::get_winner_total(int& o, int& w, int& t)
{
	
	//
	
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
	
	
	out << "\n";

	for (auto &game : manager.games)
	{
		out << *game;

	}

	out << "\nO wins: " << manager.o_win << "\n";
	out << "X wins: " << manager.x_win << "\n";
	out << "Ties  : " << manager.ties << "\n";

	return out;

}
