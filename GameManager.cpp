//
// Created by mathi on 2/7/2020.
//

#include <iostream>
#include "GameManager.h"
#include "CharacterCreator.h"
#include "Formater.h"

using std::cout;
using std::cin;
using std::endl;

void GameManager::startGame() {
    cout << "Welcome to NetherStorm!" << endl;
    cout << "How many players per team?" << endl;
    int numberOfPlayers;
    cin >> numberOfPlayers;

    createPlayers(numberOfPlayers);
    Formater::displayPlayers(players);

}

void GameManager::createPlayers(int numberOfPlayers) {
    for (int i = 0; i < numberOfPlayers*2; i++) {
        Formater::clear();
        int playerNumber = (i%numberOfPlayers)+1;
        std::string ordinalIndicator = playerNumber==1 ? "st" : playerNumber == 2 ? "nd" : playerNumber == 3 ? "rd" : "th";
        std::string team = i < numberOfPlayers ? "blue" : "red";
        cout << endl << playerNumber << ordinalIndicator << " player of the " << team << " team. Your turn." << endl;
        CharacterCreator cc;
        this->players.emplace_back(cc.createPlayer());
    }
}



