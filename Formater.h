//
// Created by mathi on 2/7/2020.
//

#ifndef ARBEIDSKRAVCPLUSPLUS_FORMATER_H
#define ARBEIDSKRAVCPLUSPLUS_FORMATER_H


#include <vector>
#include <iostream>
#include "Character.h"


class Formater {
public:
    static void clear();
    static void displayPlayers(const std::vector<Character *> &players, bool withAttacks, bool withPlayerIndex = false);

    static void displayCharacterAttacks(Character character, bool withActionIndex = false, bool withCurrentCooldown = false);

    static void displayCharacterAttack(Attack * &attack, bool withCurrentCooldown);

    static void printIndex(int i);
};


#endif //ARBEIDSKRAVCPLUSPLUS_FORMATER_H
