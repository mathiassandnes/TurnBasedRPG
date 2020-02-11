//
// Created by mathi on 2/8/2020.
//

#include "CharacterView.h"

#include <utility>
#include "Formater.h"

void CharacterView::promptAction(Character &character) {
    Formater::displayCharacterAttacks(character, true, true);
}

void CharacterView::printStatus() {


}
