//h
#include"tic_tac_toe.h"
#include"tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"
#include"tic_tac_toe_manager.h"
#include<memory>
#include<vector>
#include<string>
#include<fstream>

using std::string;using std::vector;
using std::unique_ptr;

#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

class TicTacToeData
{
public:
	void save_games(const std::vector<std::unique_ptr<TicTacToe>>& games);
	vector<unique_ptr<TicTacToe>> get_games();
private:
	const string file_name{ "tictactoedata.txt" };
};


#endif // !TIC_TAC_TOE_DATA_H
