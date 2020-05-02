//h
#ifndef TIC_TAC_TOE_H //Header Guard
#define TIC_TAC_TOE_H
#include <string>
#include <vector>




using std::vector;
using std::string;
//Add const class function get_pegs that returns a vector of strings
//return the pegs vector
class TicTacToe
{
public:
	TicTacToe(int size) : pegs(size* size, " ") {}
	TicTacToe(std::vector<string> p, string win) :pegs{ p },  winner{ win } {}//more code here to
		//initialize the pegs vector with p and initialize winner.
	bool game_over();
	void start_game(string first_player);
	void mark_board(int position);
	vector<string> get_pegs() const{ return pegs; }
	string get_player() const { return next_player; }
	string get_winner() const { return winner; }
	friend std::istream& operator>>(std::istream& in, TicTacToe& b);
	friend std::ostream& operator<<(std::ostream& out, const TicTacToe& b);

protected:
	vector<string>pegs;
	virtual bool check_column_win();
	virtual bool check_row_win();
	virtual bool check_diagonal_win();
	virtual void set_winner();
	

private:
	bool check_board_full();
	string player{ "" };
	string next_player{ "" };
	string winner{ "" };
	void set_next_player() ;
	void clear_board();

};

#endif

#ifndef ERROR_H
#define ERROR_H

class Error
{
public:
	Error(std::string msg) : message{ msg } {}
	std::string get_message()const { return message; }

private:
	std::string message;
};

#endif // !ERROR_H