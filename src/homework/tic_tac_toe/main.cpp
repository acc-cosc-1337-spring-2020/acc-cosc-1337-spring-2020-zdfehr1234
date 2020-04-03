#include<iostream>
#include "tic_tac_toe.h"

using std::cout;
using std::cin;


int main() 
{
	string player1;
	int position;
	auto choice{ 'y' };
	int err{ 0 };

	do
	{
		TicTacToe game;
		do
		{
			err = 0;
			cout << "Enter first player (X/O): ";
			cin >> player1;

			try
			{
				game.start_game(player1);
			}
			catch (Error e)
			{
				cout << e.get_message() << "\n";
				err = 1;
			}
		} while (err != 0);

		while (game.game_over() == false)
		{
			player1 = game.get_player();
			do
			{
				err = 0;
				cout << "\nPlayer " << player1 << " enter a position (1 to 9): ";
				cin >> position;
				try
				{
					game.mark_board(position);
				}
				catch (Error e)
				{
					cout << e.get_message() << "\n";
					err = 1;
				}
			} while (err != 0);
			cout << "_______________________________________________________________________\n";
			game.display_board();

		}
		if (game.get_winner() == "C")
		{
			cout << "\nTie!";
		}
		else
		{
			cout << "\n\n" << game.get_winner() << " is the winner!!\n";
		}

		cout << "\nPlay again? (y/n)";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');
	
}

