//h
#include <string>

using std::string;

class TicTacToe
{
public:
	void start_game(string first_player);
	void mark_board(int position);
	string get_player() const { return next_player; }
	

private:
	string player{ "" };
	string next_player{ "" };
	void set_next_player() ;

};

class Error
{
public:
	Error(std::string msg) : message{ msg } {}
	std::string get_message()const { return message; }

private:
	std::string message;
};