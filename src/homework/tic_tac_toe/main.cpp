#include<iostream>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

using std::cout;
using std::cin;


int main()
{
	//std::vector <std::reference_wrapper<TicTacToe>> game;
	int position;
	auto choice{ 'y' };
	int err{ 0 };
	int type;
	string player1;

	TicTacToeManager manager;

	do
	{
		cout << "Welcome please select 3 or 4 in a row: ";
		cin >> type;

		if (type == 3)
		{
			TicTacToe3 game3;
			do
			{
				err = 0;
				cout << "Enter first player (X/O): ";
				cin >> player1;

				try
				{
					game3.start_game(player1);
				}
				catch (Error e)
				{
					cout << e.get_message() << "\n";
					err = 1;
				}
			} while (err != 0);

			while (game3.game_over() == false)
			{
				player1 = game3.get_player();
				do
				{
					err = 0;
					cin >> game3;

				} while (err != 0);

				cout << game3 << "\n";
				cout << "_______________________________________________________________________\n";


			}
			if (game3.get_winner() == "C")
			{
				cout << "\nTie!\n";
				manager.save_game(game3);
				cout << game3;
				cout << manager;
			}
			else
			{
				cout << "\n\n" << game3.get_winner() << " is the winner!!\n";
				manager.save_game(game3);
				cout << game3 << "\n";
				cout << manager << "\n";
			}

			cout << "\nPlay again? (y/n)";
			cin >> choice;
			cout << "\n_______________________________________________________________________\n";

		}
		else if (type == 4)
		{
			TicTacToe4 game3;
			do
			{
				err = 0;
				cout << "Enter first player (X/O): ";
				cin >> player1;

				try
				{
					game3.start_game(player1);
				}
				catch (Error e)
				{
					cout << e.get_message() << "\n";
					err = 1;
				}
			} while (err != 0);

			while (game3.game_over() == false)
			{
				player1 = game3.get_player();
				do
				{
					err = 0;
					cin >> game3;

				} while (err != 0);

				cout << game3 << "\n";
				cout << "_______________________________________________________________________\n";


			}
			if (game3.get_winner() == "C")
			{
				cout << "\nTie!\n";
				manager.save_game(game3);
				cout << game3;
				cout << manager;
			}
			else
			{
				cout << "\n" << game3.get_winner() << " is the winner!!\n\n";
				manager.save_game(game3);
				cout << game3 << "\n\n";
				cout << manager << "\n";
			}

			cout << "\nPlay again? (y/n)";
			cin >> choice;
			cout << "\n_______________________________________________________________________\n";

		}


	} while (choice == 'y' || choice == 'Y');
	cout << "\n" << manager << "\n";
	return 0;
}

