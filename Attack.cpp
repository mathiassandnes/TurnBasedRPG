//
// Created by mathi on 2/7/2020.
//

#include "Character.h"
#include "Attack.h"

bool Attack::isReady() {
    return m_turnsSinceUse >= m_cooldown;
}

void Attack::attack(Character* target) {
    target->takeDamage(m_damage);
    m_turnsSinceUse = 0;
}

void Attack::wasNotUsed() {
    m_turnsSinceUse++;
}

int Attack::getDamage(){
    return m_damage;
}

int Attack::getCooldown(){
    return m_cooldown;
}

int Attack::getTurnsSinceUse(){
    return m_turnsSinceUse;
}

const std::string Attack::getName(){
    return m_name;
}
