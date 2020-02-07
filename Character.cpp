//
// Created by mathi on 2/7/2020.
//

#include "Character.h"
#include "Attack.h"




void Character::takeDamage(int damage) {
    m_hitpoints -= damage;
}

std::string Character::getName() {
    return m_name;
}

std::vector<Attack> Character::getAttacks() {
    return m_attacks;
}

void Character::addAttack(Attack attack) {
    if(numberOfAttacksLimit > m_attacks.size())
        m_attacks.emplace_back(attack);
}

int Character::getHP() {
    return m_hitpoints.getHP();
}

int Character::getAC() {
    return m_hitpoints.getAC();
}
