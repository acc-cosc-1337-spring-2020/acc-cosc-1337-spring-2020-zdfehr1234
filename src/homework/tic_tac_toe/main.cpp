
#include<iostream>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

using std::cout;
using std::cin;
using std::unique_ptr;
using std::make_unique;


int main()
{
	
	unique_ptr<TicTacToeManager> manager = std::make_unique<TicTacToeManager>();
	std::vector<std::unique_ptr<TicTacToe>> games;
	unique_ptr<TicTacToe> game;
	
	int position;
	auto choice{ 'y' };
	int err{ 0 };
	int type;
	string player1;

	

	do
	{
		cout << "Welcome please select 3 or 4 in a row: ";
		cin >> type;

		if (type == 3)
		{
			game = make_unique<TicTacToe3>();

		}
		else if (type == 4)
		{
			game = make_unique<TicTacToe4>();
		}
		
		

		
			
			do
			{
				err = 0;
				cout << "Enter first player (X/O): ";
				cin >> player1;

				try
				{
					game->start_game(player1);
				}
				catch (Error e)
				{
					cout << e.get_message() << "\n";
					err = 1;
				}
			} while (err != 0);

			while (game->game_over() == false)
			{
				player1 = game->get_player();
				do
				{
					err = 0;
					cin >> *game;

				} while (err != 0);

				cout << *game << "\n";
				cout << "_______________________________________________________________________\n";


			}
			if (game->get_winner() == "C")
			{
				cout << "\nTie!\n";
				manager->save_game(game);
				cout << *game << "\n";
				cout << *manager;
			}
			else
			{
				cout << "\n\n" << game->get_winner() << " is the winner!!\n";
				manager->save_game(game);
				cout << *game << "\n";
				cout << *manager << "\n";
			}

			cout << "\nPlay again? (y/n)";
			cin >> choice;
			cout << "\n_______________________________________________________________________\n";

		
		


	} while (choice == 'y' || choice == 'Y');
	cout << "\n" << manager << "\n";
	return 0;
}


