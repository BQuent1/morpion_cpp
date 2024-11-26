#include <iostream>
#include "Player.h"
#include <array>

Player create_player()
{
    std::string player_name;
    char player_symbol;
    std::cin >> player_name;
    std::cin >> player_symbol;

    return Player{player_name, player_symbol};
}

void draw_game_board(std::array<char, 9> tab_joueur)
{
    std::cout << "    A   B   C\n";
    std::cout << 1;

    for (int i = 0; i < 3; i++)
    {
        std::cout << " | " << tab_joueur[i];
    }
    std::cout << "\n";
    std::cout << 2;
    for (int j = 3; j < 6; j++)
    {
        std::cout << " | " << tab_joueur[j];
    }
    std::cout << "\n";
    std::cout << 3;
    for (int k = 6; k < 9; k++)
    {
        std::cout << " | " << tab_joueur[k];
    }
    
}

int main()
{
    std::array<char, 9> tab{'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    draw_game_board(tab);
    return 0;
}