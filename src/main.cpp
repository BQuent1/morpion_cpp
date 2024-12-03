#include <iostream>
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <array>
#include <string>

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

    return false;
}

bool is_match_nul(std::array<char, 9> tab)
{
    for (int i = 0; i < 9; i++)
    {
        if (tab[i] == ' ')
        {
            return false;
        }
    }

    return true;
}

void game_start(Player player1, Player player2, std::array<char, 9> tab, int mode, int niveau_ia = NULL)
{
    std::srand(static_cast<unsigned>(std::time(0)));
    char symbol_playing{};
    Player current_player{};
    int current_player_index{};

    int kicommence = 1 + (std::rand() % 2);
    if (kicommence == 1)
    {
        std::cout << "\n"
                  << player1.name << " tu commences\n";
        current_player = player1;
        current_player_index = 1;
    }

    else
    {
        if (mode == 1) // si mode de jeu a deux
        {
            std::cout << "\n"
                      << player2.name << " tu commences\n";
            current_player = player1;
            current_player_index = 2;
        }
        else // mode solo
        {
            std::cout << "\nL'IA commence";
            current_player = player2;
            current_player_index = 2;
        }
    }

    draw_game_board(tab);

    while (!is_game_over(tab) and !is_match_nul(tab))
    {

        if (mode == 1)
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
                current_player_index = 2;
            }
            else
            {
                current_player = player1;
                current_player_index = 1;
            }
        }

        else // mode solo
        {
            if (current_player_index == 2)
            {
                std::cout << "Reflexion en cours";
                _sleep(500);
                std::cout << ".";
                _sleep(500);
                std::cout << ".";
                _sleep(500);
                std::cout << ".";
                _sleep(500);

                if (niveau_ia == 1)
                {
                    int random_index = 1 + (std::rand() % 9);
                    while (tab[random_index] != ' ')
                    {
                        random_index = 1 + (std::rand() % 9);
                    }
                    tab[random_index] = current_player.symbole;
                }

                else if (niveau_ia == 2)
                {
                    int choix_case{10};
                    for (int i = 0; i < tab.size(); i++)
                    {
                        if (tab[i] == ' ')
                        {
                            switch (i)
                            {
                            case 0:
                                if ((tab[1] == tab[2] && tab[1] != ' ') ||
                                    (tab[3] == tab[6] && tab[3] != ' ') ||
                                    (tab[4] == tab[8] && tab[4] != ' '))
                                {
                                    choix_case = 0;
                                }
                                break;
                            case 1:
                                if ((tab[0] == tab[2] && tab[0] != ' ') ||
                                    (tab[4] == tab[7] && tab[4] != ' '))
                                {
                                    choix_case = 1;
                                }
                                break;
                            case 2:
                                if ((tab[0] == tab[1] && tab[0] != ' ') ||
                                    (tab[4] == tab[6] && tab[4] != ' ') ||
                                    (tab[5] == tab[8] && tab[5] != ' '))
                                {
                                    choix_case = 2;
                                }
                                break;
                            case 3:
                                if ((tab[0] == tab[6] && tab[0] != ' ') ||
                                    (tab[4] == tab[5] && tab[4] != ' '))
                                {
                                    choix_case = 3;
                                }
                                break;
                            case 4:
                                if ((tab[0] == tab[8] && tab[0] != ' ') ||
                                    (tab[1] == tab[7] && tab[1] != ' ') ||
                                    (tab[2] == tab[6] && tab[2] != ' ') ||
                                    (tab[3] == tab[5] && tab[3] != ' '))
                                {
                                    choix_case = 4;
                                }
                                break;
                            case 5:
                                if ((tab[2] == tab[8] && tab[2] != ' ') ||
                                    (tab[4] == tab[3] && tab[4] != ' '))
                                {
                                    choix_case = 5;
                                }
                                break;
                            case 6:
                                if ((tab[0] == tab[3] && tab[0] != ' ') ||
                                    (tab[7] == tab[8] && tab[7] != ' ') ||
                                    (tab[4] == tab[2] && tab[4] != ' '))
                                {
                                    choix_case = 6;
                                }
                                break;
                            case 7:
                                if ((tab[6] == tab[8] && tab[6] != ' ') ||
                                    (tab[4] == tab[1] && tab[4] != ' '))
                                {
                                    std::cout << "\nprends le 7\n";
                                    choix_case = 7;
                                }
                                break;
                            case 8:
                                if ((tab[7] == tab[6] && tab[7] != ' ') ||
                                    (tab[4] == tab[0] && tab[4] != ' ') ||
                                    (tab[5] == tab[2] && tab[5] != ' '))
                                {
                                    choix_case = 8;
                                }
                                break;

                            default:
                                break;
                            }
                        }
                        std::cout << "\n i:" << i << " choix : " << choix_case << "\n";
                    }

                    if (choix_case == 10)
                    {
                        int random_index = 1 + (std::rand() % 9);
                        while (tab[random_index] != ' ')
                        {
                            random_index = 1 + (std::rand() % 9);
                        }
                        tab[random_index] = current_player.symbole;
                    }
                    else
                    {
                        tab[choix_case] = current_player.symbole;
                    }
                }

                draw_game_board(tab);
            }
            else
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
            }

            if (current_player.name == player1.name)
            {
                current_player = player2;
                current_player_index = 2;
            }
            else
            {
                current_player = player1;
                current_player_index = 1;
            }
        }
    }

    if (is_game_over(tab))
    {
        if (current_player.name == player1.name)
        {
            std::cout << "\n"
                      << player2.name << " a gagne, t nul\n";
        }
        else if (current_player.name == player2.name)
        {
            std::cout << "\n"
                      << player1.name << " a gagne, bien ouej\n";
        }
    }

    else if (is_match_nul(tab))
    {
        std::cout << "\nMatch nul !";
        return;
    }
}

int main()
{
    std::array<char, 9> tab{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int mode_jeu{};
    std::cout << "Bienvenue dans le jeu du TicTacToe \nVeuillez choisir un mode de jeu : \n1. Deux joueurs\n2. Un joueur contre l'IA\n";
    std::cin >> mode_jeu;

    if (mode_jeu == 1) // mode de jeu multi-joueurs
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

        game_start(create_player(nom_joueur_1, symbole_joueur_1), create_player(nom_joueur_2, symbole_joueur_2), tab, mode_jeu);
    }

    else // mode de jeu solo
    {
        std::string nom_joueur_1{};
        char symbole_joueur_1{};
        char symbole_ia{'O'};
        int niveau_ia{1};
        std::cout << "Joueur 1, quel est ton nom ?\n";
        std::cin >> nom_joueur_1;
        std::cout << nom_joueur_1 << ", quel symbole prends tu ?\n";
        std::cin >> symbole_joueur_1;
        std::cout << nom_joueur_1 << ", quel niveau d'IA prends tu ?\n 1:facile\n2:pas tres complique\n";
        std::cin >> niveau_ia;

        if (symbole_joueur_1 == symbole_ia)
        {
            symbole_ia = 'X';
        }

        game_start(create_player(nom_joueur_1, symbole_joueur_1), create_player("IA", symbole_ia), tab, mode_jeu, niveau_ia);
    }

    return 0;
}