#include<iostream>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

using std::cout;
using std::cin;


int main() 
{
	int position;
	auto choice{ 'y' };
	int err{ 0 };

	TicTacToeManager manager;

	do
	{
		string player1;
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
				cin >> game;
				
			} while (err != 0);
			
			cout << game << "\n"; 
			cout << "_______________________________________________________________________\n";
			

		}
		if (game.get_winner() == "C")
		{
			cout << "\nTie!\n";
			manager.save_game(game);
			cout << game;
			cout << manager;
		}
		else
		{
			cout << "\n\n" << game.get_winner() << " is the winner!!\n";
			manager.save_game(game);
			cout << game << "\n";
			cout << manager << "\n";
		}

		cout << "\nPlay again? (y/n)";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');
	
	cout << "\n" << manager;
}

