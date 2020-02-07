#include <utility>

//
// Created by mathi on 2/7/2020.
//

#ifndef ARBEIDSKRAVCPLUSPLUS_ATTACK_H
#define ARBEIDSKRAVCPLUSPLUS_ATTACK_H


class Character;

class Attack {
private:
    int m_damage;
    int m_cooldown;
    int m_turnsSinceUse;
    std::string m_name;
public:
    Attack(int damage, int cooldown, std::string name) : m_damage(damage), m_cooldown(cooldown), m_name(std::move(name)) {}
    void attack(Character* target);
    void wasNotUsed();
    bool isReady();

    int getDamage();
    int getCooldown();
    int getTurnsSinceUse();
    const std::string getName();


};
#endif //ARBEIDSKRAVCPLUSPLUS_ATTACK_H
