#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test can’t call mark board before start game")

{
    TicTacToe game;
    REQUIRE_THROWS_AS(game.mark_board(1), Error);
}

TEST_CASE("Test start game accepts only X or O")
{
    TicTacToe game1;
    REQUIRE_THROWS_AS(game1.start_game("S"), Error);

    TicTacToe game2;
    REQUIRE_THROWS_AS(game1.start_game("h"), Error);

}

TEST_CASE("Test set first player to X")
{
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test set first player to O")
{
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test start game with X game flow")
{
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
    game.mark_board(4);
    REQUIRE(game.get_player() == "O");


}

TEST_CASE("Test start game with O game flow")
{
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
    game.mark_board(4);
    REQUIRE(game.get_player() == "X");


}

TEST_CASE("Test game ends when board is full and returns tie")
{
	TicTacToe game; 
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
}

TEST_CASE("Test mark position accepts values from 1 to 9 only")
{
    TicTacToe game1;
    game1.start_game("X");
    REQUIRE_THROWS_AS(game1.mark_board(10), Error);

    TicTacToe game2;
    game1.start_game("X");
    REQUIRE_THROWS_AS(game2.mark_board(0), Error);

}

TEST_CASE("Test win by first column")
{
    TicTacToe board;
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
    REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win by second column")
{
    TicTacToe board;
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
    REQUIRE(board.get_winner() == "O");
}

TEST_CASE("Test win by third column")
{
    TicTacToe board;
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
    REQUIRE(board.get_winner() == "O");
}

TEST_CASE("Test win by first row")
{
    TicTacToe board;
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
    REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win by second row")
{
    TicTacToe board;
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
    REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win by third row")
{
    TicTacToe board;
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
    REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left")
{
    TicTacToe board;
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
    REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left")
{
    TicTacToe board;
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
    REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test for no winner")
{
    TicTacToe game;
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
}