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
	

private:
	bool check_board_full();
	string player{ "" };
	string next_player{ "" };
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