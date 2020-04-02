//h
#include <string>
#include <vector>


using std::vector;
using std::string;

class TicTacToe
{
public:
	bool game_over();
	void start_game(string first_player);
	void mark_board(int position);
	void display_board() const;
	string get_player() const { return next_player; }
	string get_winner() const { return winner; }

	

private:
	bool check_board_full();
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();
	void set_winner();
	string player{ "" };
	string next_player{ "" };
	string winner{ "" };
	void set_next_player() ;
	std::vector<std::string> pegs{ 9, " " };
	void clear_board();

};

class Error
{
public:
	Error(std::string msg) : message{ msg } {}
	std::string get_message()const { return message; }

private:
	std::string message;
};