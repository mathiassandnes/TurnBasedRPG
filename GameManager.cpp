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

    run();

}

void GameManager::createPlayers(int numberOfPlayers) {
    for (int i = 0; i < numberOfPlayers * 2; i++) {
        Formater::clear();
        int playerNumber = (i % numberOfPlayers) + 1;
        std::string ordinalIndicator =
                playerNumber == 1 ? "st" : playerNumber == 2 ? "nd" : playerNumber == 3 ? "rd" : "th";
        std::string team = i < numberOfPlayers ? "blue" : "red";
        cout << endl << playerNumber << ordinalIndicator << " player of the " << team << " team. Your turn." << endl;
        CharacterCreator cc;
        this->players.emplace_back(cc.createPlayer());
    }
}

void GameManager::run() {

    std::size_t const half_size = players.size() / 2;
    std::vector<Character *> blueTeam(players.begin(), players.begin() + half_size);
    std::vector<Character *> redTeam(players.begin() + half_size, players.end());


    Formater::clear();
    cout << "---------------------------------------" << endl;
    cout << "BLUE TEAM:" << endl;
    Formater::displayPlayers(blueTeam, true);
    cout << "---------------------------------------" << endl << endl;

    cout << "---------------------------------------" << endl;
    cout << "RED TEAM:" << endl;
    Formater::displayPlayers(redTeam, true);
    cout << "---------------------------------------" << endl;

    std::string dummyString;
    cin >> dummyString;
    Formater::clear();

    int blueTeamSize = blueTeam.size() - 1;
    int redTeamSize = redTeam.size() - 1;
    int blueTeamCounter = 0;
    int redTeamCounter = 0;
    bool blueTeamTurn = true;

    while (true) {
        if (blueTeamTurn) {
            gameTurn(blueTeam, redTeam, blueTeamSize, blueTeamCounter, false);
        } else {
            gameTurn(redTeam, blueTeam, redTeamSize, redTeamCounter, true);
        }
        Formater::displayPlayers(players, false, false);


        removeDeadPlayersOnTeam(redTeam, redTeamSize, redTeamCounter);
        removeDeadPlayersOnTeam(blueTeam, blueTeamSize, blueTeamCounter);

        if (redTeam.empty() && blueTeam.empty()) {
            Formater::clear();
            cout << "It's a draw" << endl;
            exit(0);
        } else if (redTeam.empty()) {
            Formater::clear();
            cout << "Blue team WON!" << endl;
            exit(0);
        } else if (blueTeam.empty()) {
            Formater::clear();
            cout << "Red team WON!" << endl;
            exit(0);
        }

        blueTeamTurn = !blueTeamTurn;

    }
}

void GameManager::gameTurn(std::vector<Character *> &team, std::vector<Character *> &enemies, int &teamSize,
                           int &teamCounter, bool isNPC) {
    if(isNPC){
        team[teamCounter]->runTurn(team, enemies, isNPC);
    } else {
        team[teamCounter]->runTurn(team, enemies, isNPC);
    }
    if (teamCounter == teamSize) {
        teamCounter = 0;
    } else {
        teamCounter++;
    }
}

void GameManager::removeDeadPlayersOnTeam(std::vector<Character *> &team, int &teamSize, int counter) const {
    int teamCounter = counter;
    for (int i = 0; i <= teamSize; i++) {
        if (!team[teamCounter]->isAlive()) {
            team.erase(team.begin() + teamCounter);
            teamSize--;
        }
    }
}



