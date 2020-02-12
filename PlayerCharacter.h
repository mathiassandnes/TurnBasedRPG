//
// Created by mathi on 2/8/2020.
//

#ifndef ARBEIDSKRAVCPLUSPLUS_PLAYERCHARACTER_H
#define ARBEIDSKRAVCPLUSPLUS_PLAYERCHARACTER_H


#include "Character.h"

class PlayerCharacter {
public:
    void runTurn(Character &character, const std::vector<Character *> &team, const std::vector<Character *> &enemies, bool NPC);

};

#endif //ARBEIDSKRAVCPLUSPLUS_PLAYERCHARACTER_H
