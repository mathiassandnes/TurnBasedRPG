//
// Created by mathi on 2/7/2020.
//

#ifndef ARBEIDSKRAVCPLUSPLUS_HP_H
#define ARBEIDSKRAVCPLUSPLUS_HP_H


class HP {
private:
    int m_HP;
    int m_MaxHP;
    int m_AC;
public:
    HP(int HP, int AC) : m_HP(HP), m_AC(AC), m_MaxHP(HP) {};
//    operator+=
    void operator-=(int damage);
//    operator==
    int getHP() const;

    int getAC() const;
};


#endif //ARBEIDSKRAVCPLUSPLUS_HP_H
