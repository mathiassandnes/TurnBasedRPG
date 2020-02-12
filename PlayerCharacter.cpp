//
// Created by mathi on 2/8/2020.
//

#include "PlayerCharacter.h"
#include "CharacterView.h"
#include "Character.h"
#include "Formater.h"

using std::cout;
using std::cin;
using std::endl;

void PlayerCharacter::runTurn(Character &character, const std::vector<Character *> &team,
                              const std::vector<Character *> &enemies, bool isNPC) {
    CharacterView cv;
    int attackIndex = 0;
    int targetIndex = 0;

    if (isNPC) {
        targetIndex = rand() % enemies.size();
        bool attackNotDecided = true;
        auto attacks = character.getAttacks();
        while(attackNotDecided) {
            attackIndex = rand() % attacks.size();
            if(attacks[attackIndex]->getCooldown() == 0){
                attackNotDecided = false;
            }
        }
    } else {
        cout << character.getName() << " your turn." << endl << endl;

        //TODO:
        ///This should be done in character view

        bool attackNotDecided = true;
        while (attackNotDecided) {
            cv.promptAction(character);
            cin >> attackIndex;
            if (character.getAttacks()[attackIndex]->getCooldown() == 0) {
                attackNotDecided = false;
                cout << "Choose a target:" << endl;
                Formater::displayPlayers(enemies, false, true);
                cin >> targetIndex;
            } else {
                cout << "That attack is still on cooldown.." << endl;
            }

        }
    }

    ///This should be done in character view

    cout << character.getName() << " attacks " << enemies[targetIndex]->getName() << " with "
         << character.getAttacks()[attackIndex]->getName() << endl;
    Formater::clear();
    character.getAttacks()[attackIndex]->attack(enemies[targetIndex]);

    for (auto attack : character.getAttacks()) {
        if (attack != character.getAttacks()[attackIndex]) {
            attack->wasNotUsed();
        }
    }


}
