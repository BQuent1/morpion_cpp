#include <iostream>
#include "Player.h"
#include <array>
#include <cstdlib>
#include <ctime>

Player create_player(std::string player_name, char player_symbol)
{
    return Player{player_name, player_symbol};
}

void draw_game_board(std::array<char, 9> tab_joueur)
{
    std::cout << "\n\n";
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
    std::cout << "\n\n";
}

#include <array>
#include <string>

bool is_game_over(std::array<char, 9> tab)
{
    for (int i = 0; i < 9; i += 3)
    {
        if (tab[i] != ' ' && tab[i] == tab[i + 1] && tab[i] == tab[i + 2])
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (tab[i] != ' ' && tab[i] == tab[i + 3] && tab[i] == tab[i + 6])
        {
            return true;
        }
    }

    if (tab[0] != ' ' && tab[0] == tab[4] && tab[0] == tab[8])
    {
        return true;
    }
    if (tab[2] != ' ' && tab[2] == tab[4] && tab[2] == tab[6])
    {
        return true;
    }

    for (int i = 0; i < 9; i++)
    {
        if (tab[i] == ' ')
        {
            return false;
        }
    }
    
    std::cout << "\nMatch nul !\n";
    return true;
}

void mode_deux_joueurs(Player player1, Player player2, std::array <char, 9> tab)
{
    draw_game_board(tab);

    std::srand(static_cast<unsigned>(std::time(0)));
    char symbol_playing{};
    Player current_player{};

    int kicommence = 1 + (std::rand() % 2);
    if (kicommence == 1)
    {
        std::cout << "\n" << player1.name << " tu commences\n";
        current_player = player1;
    }
    else
    {
        std::cout << "\n" << player2.name << " tu commences\n";
        current_player = player2;
    }

    draw_game_board(tab);

    while (!is_game_over(tab))
    {
        std::string pos;
        std::cout << current_player.name << ", entre une position (ex: A1) : ";
        std::cin >> pos;

        int index = -1;
        if (pos == "A1")
            index = 0;
        else if (pos == "B1")
            index = 1;
        else if (pos == "C1")
            index = 2;
        else if (pos == "A2")
            index = 3;
        else if (pos == "B2")
            index = 4;
        else if (pos == "C2")
            index = 5;
        else if (pos == "A3")
            index = 6;
        else if (pos == "B3")
            index = 7;
        else if (pos == "C3")
            index = 8;

        if (index == -1 || tab[index] != ' ')
        {
            std::cout << "\nPosition invalide ou deja occupee, reessaye.\n";
            continue;
        }

        tab[index] = current_player.symbole;

        draw_game_board(tab);

        if (current_player.name == player1.name)
        {
            current_player = player2;
        }
        else
        {
            current_player = player1;
        }
    }

    if (is_game_over(tab))
    {
        if (current_player.name == player1.name)
        {
            std::cout << "\n" << player2.name << " tu as gagne, bien ouej\n";
        }
        else if(current_player.name == player2.name)
        {
            std::cout << "\n" << player1.name << " tu as gagne, bien ouej\n";
        }
    }
}

int main()
{
    std::array<char, 9> tab{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int mode_jeu{};
    std::cout << "Bienvenue dans le jeu du TicTacToe \nVeuillez choisir un mode de jeu : \n1. Deux joueurs\n2. Un joueur contre l'IA\n";
    std::cin >> mode_jeu;

    if (mode_jeu == 1) //mode de jeu multi-joueurs
    {
        std::string nom_joueur_1{};
        std::string nom_joueur_2{};
        char symbole_joueur_1{};
        char symbole_joueur_2{};

        std::cout << "Joueur 1, quel est ton nom ?\n";
        std::cin >> nom_joueur_1;
        std::cout << nom_joueur_1 << ", quel symbole prends tu ?\n";
        std::cin >> symbole_joueur_1;

        std::cout << "Joueur 2, quel est ton nom ?\n";
        std::cin >> nom_joueur_2;
        std::cout << nom_joueur_2 << ", quel symbole prends tu ?\n";
        std::cin >> symbole_joueur_2;

        mode_deux_joueurs(create_player(nom_joueur_1,symbole_joueur_1), create_player(nom_joueur_2,symbole_joueur_2), tab);
    }


    return 0;
}