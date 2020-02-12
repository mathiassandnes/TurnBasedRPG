//
// Created by mathi on 2/7/2020.
//

#ifndef ARBEIDSKRAVCPLUSPLUS_GAMEMANAGER_H
#define ARBEIDSKRAVCPLUSPLUS_GAMEMANAGER_H


#include <vector>
#include "Character.h"

class GameManager {
private:
    std::vector<Character*> players;
public:
    void startGame();
    void createPlayers(int numberOfPlayers);
    void run();

    void gameTurn(std::vector<Character *> &team, std::vector<Character *> &enemies, int &teamSize,
                  int &teamCounter, bool isNPC);

    void removeDeadPlayersOnTeam(std::vector<Character *> &team, int &teamSize, int counter) const;
};


#endif //ARBEIDSKRAVCPLUSPLUS_GAMEMANAGER_H
