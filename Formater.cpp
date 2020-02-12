//
// Created by mathi on 2/7/2020.
//


#include "Formater.h"
using std::cout;
using std::endl;


void Formater::clear() {
    cout << endl << endl << endl << endl << endl;
}

void Formater::displayPlayers(const std::vector<Character *> &players, bool withAttacks, bool withPlayerIndex) {
    int playersLength = players.size();
    for(int i = 0; i < playersLength; i++){
        cout << "-----------------------------------" << endl;
        if(withPlayerIndex){
            printIndex(i);
        }
        cout << players[i]->getName() << " | " << players[i]->getTypeOfCharacter() << " | HP: " << players[i]->getHP() << " | AC: " << players[i]->getAC() << endl;
        if(withAttacks){
            cout << "Attacks:" << endl;
            displayCharacterAttacks(*players[i], false, false);
        }

    }
    cout << "-----------------------------------" << endl << endl << endl;

}

void Formater::printIndex(int i) { cout << "(" << i << ") "; }

void Formater::displayCharacterAttacks(Character character, bool withActionIndex, bool withCurrentCooldown) {
    std::vector<Attack*> attacks = character.getAttacks();
    int attacksLength = attacks.size();
    for(int i = 0; i < attacksLength; i++){
        if(withActionIndex){
            printIndex(i);
        }
        displayCharacterAttack(attacks[i], withCurrentCooldown);
    }
}

void Formater::displayCharacterAttack(Attack * &attack, bool withCurrentCooldown = false) {
    cout << attack->getName() << " | Damage: " << attack->getDamage();
    if(withCurrentCooldown){
        cout << " | Turn until next use: " << attack->getCooldown();
    } else {
        cout << " | Cooldown: " << attack->getDefaultCooldown();
    }
    cout << endl;

}

