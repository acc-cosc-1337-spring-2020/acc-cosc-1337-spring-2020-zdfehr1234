//cpp
#include"tic_tac_toe_data.h"

void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToe>>& games)
{
	std::ofstream file_out(file_name, std::ios_base::trunc);

	for (auto& game : games)
	{
		vector<string> peg = game->get_pegs();
		for (auto p : peg)
		{
			file_out << p;
		}
		file_out << game->get_winner();
		file_out << "\n";
	}
	file_out.close();

}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
	std::ifstream open_file("tictactoe.txt");
	std::vector<unique_ptr<TicTacToe>> boards;

	while (open_file.is_open())
	{
		vector<string> p{};
		string line;
		while (getline(open_file, line))
		{
	
			for (auto i = 0; i <line.size() - 1; i++)
			{
				string string(1, i);
				p.push_back(string);

			}
			string winner = p[-1];
			unique_ptr<TicTacToe> game;
			if (p.size() == 9)
			{
				game = std::make_unique<TicTacToe4>(p, winner);
			}
		}
	}
	open_file.close();
	return boards;
}
