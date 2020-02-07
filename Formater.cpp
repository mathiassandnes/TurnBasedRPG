//
// Created by mathi on 2/7/2020.
//


#include "Formater.h"
using std::cout;
using std::endl;


void Formater::clear() {
    for(int i = 0; i < 10; i++){
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    }
}

void Formater::displayPlayers(std::vector<Character> players) {
    clear();
    for(Character player : players){
        cout << "name: " << player.getName() << " | HP: " << player.getHP() << " | AC: " << player.getAC() << endl;
        cout << "Attacks:" << endl;
        std::vector<Attack> attacks = player.getAttacks();
        for(Attack attack : attacks){
            cout << "name: " << attack.getName() << " | Damage: " << attack.getDamage() << " | Cooldown: " << attack.getCooldown() << endl;
        }



    }
}

