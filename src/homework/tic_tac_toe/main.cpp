#include<iostream>
#include "tic_tac_toe.h"

using std::cout;
using std::cin;


int main() 
{
	string player1;
	int position;
	auto choice{ 'y' };

	TicTacToe game;
	cout << "Enter first player (X/O): ";
	cin >> player1;
	
	try
	{
		game.start_game(player1);
	}
	catch (Error e)
	{
		cout << e.get_message() << "\n";
	}
	
	

	do
	{
		player1 = game.get_player();
		cout << "Player "<< player1 << " enter a position (1 to 9): ";
		cin >> position;

		try
		{
			game.mark_board(position);
		}
		catch (Error e)
		{
			cout << e.get_message() << "\n";
		}

		cout << "Continue? (y/n)";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');

	
}

