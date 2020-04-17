#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test can’t call mark board before start game")

{
    TicTacToe3 game;
    REQUIRE_THROWS_AS(game.mark_board(1), Error);

	TicTacToe4 game2;
	REQUIRE_THROWS_AS(game2.mark_board(1), Error);
}

TEST_CASE("Test start game accepts only X or O")
{
    TicTacToe3 game1;
    REQUIRE_THROWS_AS(game1.start_game("S"), Error);

    TicTacToe4 game2;
    REQUIRE_THROWS_AS(game1.start_game("h"), Error);

}

TEST_CASE("Test set first player to X")
{
    TicTacToe3 game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");

	TicTacToe4 game2;
	game2.start_game("X");
	REQUIRE(game2.get_player() == "X");
}

TEST_CASE("Test set first player to O")
{
    TicTacToe3 game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");

	TicTacToe4 game2;
	game2.start_game("O");
	REQUIRE(game2.get_player() == "O");
}

TEST_CASE("Test start game with X game flow")
{
    TicTacToe3 game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
    game.mark_board(4);
    REQUIRE(game.get_player() == "O");

	TicTacToe4 game2;
	game2.start_game("X");
	REQUIRE(game2.get_player() == "X");
	game2.mark_board(4);
	REQUIRE(game2.get_player() == "O");

}

TEST_CASE("Test start game with O game flow")
{
    TicTacToe3 game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
    game.mark_board(4);
    REQUIRE(game.get_player() == "X");

	TicTacToe4 game2;
	game2.start_game("O");
	REQUIRE(game2.get_player() == "O");
	game2.mark_board(4);
	REQUIRE(game2.get_player() == "X");


}

TEST_CASE("Test game ends when board is full and returns tie")
{
	TicTacToe3 game; 
	game.start_game("X");

    game.mark_board(1); //X
    REQUIRE(game.game_over() == false);
    game.mark_board(2); //O
    REQUIRE(game.game_over() == false);
    game.mark_board(5); //X
    REQUIRE(game.game_over() == false);
    game.mark_board(3); //O
    REQUIRE(game.game_over() == false);
    game.mark_board(6); //X
    REQUIRE(game.game_over() == false);
    game.mark_board(4); //O
    REQUIRE(game.game_over() == false);
    game.mark_board(7); //X
    REQUIRE(game.game_over() == false);
    game.mark_board(9); //O
    REQUIRE(game.game_over() == false);
    game.mark_board(8);//X
    
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");

	TicTacToe4 game2;
	game2.start_game("X");

	game2.mark_board(1); //X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(2); //O
	REQUIRE(game2.game_over() == false);
	game2.mark_board(5); //X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(3); //O
	REQUIRE(game2.game_over() == false);
	game2.mark_board(6); //X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(4); //O
	REQUIRE(game2.game_over() == false);
	game2.mark_board(7); //X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(9); //O
	REQUIRE(game2.game_over() == false);
	game2.mark_board(10);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(8);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(11);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(12);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(13);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(14);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(15);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(16);//X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test mark position for 3x3 game accepts values from 1 to 9 only")
{
    TicTacToe3 game1;
    game1.start_game("X");
    REQUIRE_THROWS_AS(game1.mark_board(10), Error);

    TicTacToe3 game2;
    game1.start_game("X");
    REQUIRE_THROWS_AS(game2.mark_board(0), Error);

}

TEST_CASE("Test mark position for 4x4 game accepts values from 1 to 16 only")
{
	TicTacToe3 game1;
	game1.start_game("X");
	REQUIRE_THROWS_AS(game1.mark_board(17), Error);

	TicTacToe3 game2;
	game1.start_game("X");
	REQUIRE_THROWS_AS(game2.mark_board(0), Error);

}

TEST_CASE("Test win by first column")
{
    TicTacToe3 board;
    board.start_game("X");
    REQUIRE(board.game_over() == false);
    board.mark_board(1);//X        
    REQUIRE(board.game_over() == false);
    board.mark_board(2);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(4);//X          
    REQUIRE(board.game_over() == false);
    board.mark_board(5);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(7);//X
    //X wins
    REQUIRE(board.game_over() == true);
    REQUIRE(board.get_winner() == "O");

	TicTacToe4 board2;
	board2.start_game("X");
	REQUIRE(board2.game_over() == false);
	board2.mark_board(1);//X        
	REQUIRE(board2.game_over() == false);
	board2.mark_board(2);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(5);//X          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(6);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(9);//X
	REQUIRE(board2.game_over() == false);
	board2.mark_board(10);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(13);//X          
	//X wins
	REQUIRE(board2.game_over() == true);
	REQUIRE(board2.get_winner() == "X");
}

TEST_CASE("Test win by second column")
{
    TicTacToe3 board;
    board.start_game("X");
    REQUIRE(board.game_over() == false);
    board.mark_board(1);//X        
    REQUIRE(board.game_over() == false);
    board.mark_board(2);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(3);//X          
    REQUIRE(board.game_over() == false);
    board.mark_board(5);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(4);//X
    REQUIRE(board.game_over() == false);
    board.mark_board(8);
    //O wins
    REQUIRE(board.game_over() == true);
    REQUIRE(board.get_winner() == "X");

	TicTacToe4 board2;
	board2.start_game("X");
	REQUIRE(board2.game_over() == false);
	board2.mark_board(1);//X        
	REQUIRE(board2.game_over() == false);
	board2.mark_board(2);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(5);//X          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(6);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(9);//X
	REQUIRE(board2.game_over() == false);
	board2.mark_board(10);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(4);//X 
	REQUIRE(board2.game_over() == false);
	board2.mark_board(14);//O
	//X wins
	REQUIRE(board2.game_over() == true);
	REQUIRE(board2.get_winner() == "O");
}

TEST_CASE("Test win by third column")
{
    TicTacToe3 board;
    board.start_game("X");
    REQUIRE(board.game_over() == false);
    board.mark_board(1);//X        
    REQUIRE(board.game_over() == false);
    board.mark_board(3);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(4);//X          
    REQUIRE(board.game_over() == false);
    board.mark_board(6);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(8);//X
    REQUIRE(board.game_over() == false);
    board.mark_board(9);
    //O wins
    REQUIRE(board.game_over() == true);
    REQUIRE(board.get_winner() == "X");

	TicTacToe4 board2;
	board2.start_game("X");
	REQUIRE(board2.game_over() == false);
	board2.mark_board(3);//X        
	REQUIRE(board2.game_over() == false);
	board2.mark_board(2);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(7);//X          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(6);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(11);//X
	REQUIRE(board2.game_over() == false);
	board2.mark_board(10);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(15);//X          
	//X wins
	REQUIRE(board2.game_over() == true);
	REQUIRE(board2.get_winner() == "X");
}

TEST_CASE("Test win by fourth row")
{
	TicTacToe4 board2;
	board2.start_game("X");
	REQUIRE(board2.game_over() == false);
	board2.mark_board(4);//X        
	REQUIRE(board2.game_over() == false);
	board2.mark_board(2);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(8);//X          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(6);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(12);//X
	REQUIRE(board2.game_over() == false);
	board2.mark_board(10);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(16);//X          
	//X wins
	REQUIRE(board2.game_over() == true);
	REQUIRE(board2.get_winner() == "X");
}

TEST_CASE("Test win by first row")
{
    TicTacToe3 board;
    board.start_game("X");
    REQUIRE(board.game_over() == false);
    board.mark_board(1);//X        
    REQUIRE(board.game_over() == false);
    board.mark_board(4);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(2);//X          
    REQUIRE(board.game_over() == false);
    board.mark_board(5);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(3);//X
    //X wins
    REQUIRE(board.game_over() == true);
    REQUIRE(board.get_winner() == "O");

	TicTacToe4 board2;
	board2.start_game("X");
	REQUIRE(board2.game_over() == false);
	board2.mark_board(4);//X        
	REQUIRE(board2.game_over() == false);
	board2.mark_board(7);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(3);//X          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(11);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(2);//X
	REQUIRE(board2.game_over() == false);
	board2.mark_board(10);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(1);//X          
	//X wins
	REQUIRE(board2.game_over() == true);
	REQUIRE(board2.get_winner() == "X");
}

TEST_CASE("Test win by second row")
{
    TicTacToe3 board;
    board.start_game("X");
    REQUIRE(board.game_over() == false);
    board.mark_board(4);//X        
    REQUIRE(board.game_over() == false);
    board.mark_board(1);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(5);//X          
    REQUIRE(board.game_over() == false);
    board.mark_board(2);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(6);//X
    //X wins
    REQUIRE(board.game_over() == true);
    REQUIRE(board.get_winner() == "O");

	TicTacToe4 board2;
	board2.start_game("X");
	REQUIRE(board2.game_over() == false);
	board2.mark_board(1);//X        
	REQUIRE(board2.game_over() == false);
	board2.mark_board(5);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(2);//X          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(6);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(3);//X
	REQUIRE(board2.game_over() == false);
	board2.mark_board(7);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(4);//X          
	//X wins
	REQUIRE(board2.game_over() == true);
	REQUIRE(board2.get_winner() == "X");
}

TEST_CASE("Test win by third row")
{
    TicTacToe3 board;
    board.start_game("X");
    REQUIRE(board.game_over() == false);
    board.mark_board(7);//X        
    REQUIRE(board.game_over() == false);
    board.mark_board(1);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(8);//X          
    REQUIRE(board.game_over() == false);
    board.mark_board(2);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(9);//X
    //X wins
    REQUIRE(board.game_over() == true);
    REQUIRE(board.get_winner() == "O");

	TicTacToe4 board2;
	board2.start_game("X");
	REQUIRE(board2.game_over() == false);
	board2.mark_board(9);//X        
	REQUIRE(board2.game_over() == false);
	board2.mark_board(7);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(10);//X          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(16);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(11);//X
	REQUIRE(board2.game_over() == false);
	board2.mark_board(1);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(12);//X          
	//X wins
	REQUIRE(board2.game_over() == true);
	REQUIRE(board2.get_winner() == "X");
}

TEST_CASE("Test win by fourthh row")
{
	TicTacToe4 board2;
	board2.start_game("X");
	REQUIRE(board2.game_over() == false);
	board2.mark_board(13);//X        
	REQUIRE(board2.game_over() == false);
	board2.mark_board(7);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(14);//X          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(11);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(15);//X
	REQUIRE(board2.game_over() == false);
	board2.mark_board(10);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(16);//X          
	//X wins
	REQUIRE(board2.game_over() == true);
	REQUIRE(board2.get_winner() == "X");
}


TEST_CASE("Test win diagonally from top left")
{
    TicTacToe3 board;
    board.start_game("X");
    REQUIRE(board.game_over() == false);
    board.mark_board(1);//X        
    REQUIRE(board.game_over() == false);
    board.mark_board(2);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(5);//X          
    REQUIRE(board.game_over() == false);
    board.mark_board(3);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(9);//X
    //X wins
    REQUIRE(board.game_over() == true);
    REQUIRE(board.get_winner() == "O");

	TicTacToe4 board2;
	board2.start_game("X");
	REQUIRE(board2.game_over() == false);
	board2.mark_board(1);//X        
	REQUIRE(board2.game_over() == false);
	board2.mark_board(7);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(6);//X          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(12);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(11);//X
	REQUIRE(board2.game_over() == false);
	board2.mark_board(10);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(16);//X          
	//X wins
	REQUIRE(board2.game_over() == true);
	REQUIRE(board2.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left")
{
    TicTacToe3 board;
    board.start_game("X");
    REQUIRE(board.game_over() == false);
    board.mark_board(7);//X        
    REQUIRE(board.game_over() == false);
    board.mark_board(1);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(5);//X          
    REQUIRE(board.game_over() == false);
    board.mark_board(2);//O          
    REQUIRE(board.game_over() == false);
    board.mark_board(3);//X
    //X wins
    REQUIRE(board.game_over() == true);
    REQUIRE(board.get_winner() == "O");

	TicTacToe4 board2;
	board2.start_game("X");
	REQUIRE(board2.game_over() == false);
	board2.mark_board(4);//X        
	REQUIRE(board2.game_over() == false);
	board2.mark_board(8);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(7);//X          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(6);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(10);//X
	REQUIRE(board2.game_over() == false);
	board2.mark_board(11);//O          
	REQUIRE(board2.game_over() == false);
	board2.mark_board(13);//X          
	//X wins
	REQUIRE(board2.game_over() == true);
	REQUIRE(board2.get_winner() == "X");
}
//_________________________________________________________________
TEST_CASE("Test for no winner")
{
    TicTacToe3 game;
    game.start_game("X");

    game.mark_board(1); //X
    REQUIRE(game.game_over() == false);
    game.mark_board(2); //O
    REQUIRE(game.game_over() == false);
    game.mark_board(5); //X
    REQUIRE(game.game_over() == false);
    game.mark_board(3); //O
    REQUIRE(game.game_over() == false);
    game.mark_board(6); //X
    REQUIRE(game.game_over() == false);
    game.mark_board(4); //O
    REQUIRE(game.game_over() == false);
    game.mark_board(7); //X
    REQUIRE(game.game_over() == false);
    game.mark_board(9); //O
    REQUIRE(game.game_over() == false);
    game.mark_board(8);//X

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");

	TicTacToe4 game2;
	game2.start_game("X");

	game2.mark_board(1); //X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(2); //O
	REQUIRE(game2.game_over() == false);
	game2.mark_board(5); //X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(3); //O
	REQUIRE(game2.game_over() == false);
	game2.mark_board(6); //X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(4); //O
	REQUIRE(game2.game_over() == false);
	game2.mark_board(7); //X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(9); //O
	REQUIRE(game2.game_over() == false);
	game2.mark_board(10);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(8);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(11);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(12);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(13);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(14);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(15);//X
	REQUIRE(game2.game_over() == false);
	game2.mark_board(16);//X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}

