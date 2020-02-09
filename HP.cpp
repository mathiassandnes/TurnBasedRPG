//
// Created by mathi on 2/7/2020.
//

#include "HP.h"

void HP::operator-=(int damage) {
    if ((damage -= m_AC) > 0)
        m_HP -= damage;
    if (m_HP < 0){
        m_HP = 0;
    }
}

int HP::getHP() const {
    return m_HP;
}

int HP::getAC() const {
    return m_AC;
}
