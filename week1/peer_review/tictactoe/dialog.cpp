#include <iostream>
#include <map>
#include <string>
#include "tictac.hpp"

using std::cout;
using std::endl;
using std::map;
using std::string;

void dialog(string key) {
    map<string,string> output;
    output["instructions"]
        = "This is a simple game of TicTacToe.\n"
          "In this game you, or another player,\n"
          "will take turns placing Xs and Os on\n"
          "the grid until you get three in a row\n"
          "or a draw is declared when there are no\n"
          "moves left.\n\n"

          "Use the numbers of the grid points to\n"
          "select a square.\n"
          "Best out of three, wins the game.\n";
    output["getin"] = "Input the row and column number to place your mark\n"
                      "in the format 'row column'";
    output["rwin"]  = "\n***Round win!***";
    output["rdraw"] = "This round was a draw";
    output["draw"]  = "Looks like the game is a draw.";
    output["p1win"] = "Player 1 wins the game!";
    output["p2win"] = "Player 2 wins the game!";
    output["again"] = "Would you like to play again?\n"
                      "y/n";
    output["taken"] = "That space is already taken. Please try again.";

    cout << output[key] << endl;
}
