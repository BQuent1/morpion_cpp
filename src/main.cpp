#include <iostream>
#include "Player.h"

Player create_player(){
    std::string player_name;
    char player_symbol;
    std::cin >> player_name;
    std::cin >> player_symbol;

    return Player{player_name,player_symbol};
}





int main(){
    std::cout << "Hello world";
    return 0;
}