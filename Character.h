//
// Created by mathi on 2/7/2020.
//

#ifndef ARBEIDSKRAVCPLUSPLUS_CHARACTER_H
#define ARBEIDSKRAVCPLUSPLUS_CHARACTER_H


#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include "HP.h"
#include "Attack.h"

class Character {
private:
    int numberOfAttacksLimit = 4;
    HP m_hitpoints;
    std::string m_name;
    std::vector<Attack*> m_attacks;
    std::string m_typeOfCharacter;
public:
    Character(int hitpoints, int AC, std::string  name, std::string  type) :
    m_hitpoints(hitpoints, AC),
    m_name(std::move(name)),
    m_typeOfCharacter(std::move(type)){};
    void takeDamage(int damage);
    void runTurn(const std::vector<Character*>& team, const std::vector<Character*>& enemies, bool isNPC);
    std::string getName();
    std::vector<Attack *> getAttacks();
    void addAttack(Attack * attack);
    int getHP();
    int getAC();
    bool isAlive();
    [[nodiscard]] const std::string &getTypeOfCharacter() const;
};


#endif //ARBEIDSKRAVCPLUSPLUS_CHARACTER_H
