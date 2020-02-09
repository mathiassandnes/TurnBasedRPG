//
// Created by mathi on 2/7/2020.
//

#ifndef ARBEIDSKRAVCPLUSPLUS_CHARACTERCREATOR_H
#define ARBEIDSKRAVCPLUSPLUS_CHARACTERCREATOR_H

#include <set>
#include <vector>
#include "Character.h"

enum playableClass{
    Wizard = 0,
    Orc = 1,
    Warrior = 2,
    Rouge = 3
};


class CharacterCreator{
private:
    std::vector<std::string> playableClassAsString = {"Wizard", "Orc", "Warrior", "Rouge"};
    std::set<std::string> names;
public:
    std::string decidePlayerName();
    playableClass decidePlayerClass();
    Character* createPlayerClass(playableClass characterClass, std::string characterName);
    Character* createPlayer();
};


#endif //ARBEIDSKRAVCPLUSPLUS_CHARACTERCREATOR_H
