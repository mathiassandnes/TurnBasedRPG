//
// Created by mathi on 2/7/2020.
//

#include "CharacterCreator.h"
#include "NameValidator.h"
#include "Formater.h"
#include "Attack.h"
#include <iostream>
#include <utility>


using std::cout;
using std::cin;
using std::endl;


Character CharacterCreator::createPlayer() {
    std::string characterName = decidePlayerName();
    playableClass characterClass = decidePlayerClass();
    return createPlayerClass(characterClass, characterName);
}


std::string CharacterCreator::decidePlayerName() {
    bool nameIsNotDecided = true;
    std::string name;

    while (nameIsNotDecided) {
        cout << "Choose a character name." << endl;
        cin >> name;
        Formater::clear();
        if (NameValidator::isNameTaken(name, names))
            cout << "That name is already used. Try a different name." << endl;
        else {
            cout << "Your name is " << name
                 << ". It cannot be changed later. Are you sure you want to use that name? (y/n)" << endl;
            std::string response;
            cin >> response;
            if (response == "y")
                nameIsNotDecided = false;
        }
    }
    names.insert(name);
    return name;
}

playableClass CharacterCreator::decidePlayerClass() {
    bool classIsNotDecided = true;
    playableClass chosenClass;

    while (classIsNotDecided) {
        Formater::clear();
        cout << endl << "You can choose a class now. What would you like to player?" << endl;
        int pickedClass;
        cout << "(0) Wizard " << " | (1) Orc" << " | (2) Warrior" << " | (3) Rouge"<< endl;
        cin >> pickedClass;




        cout << typeid(pickedClass).name();
        ///TODO: validate input






        Formater::clear();
        cout << "You choose to be a";

        switch (pickedClass) {
            case 0:
                chosenClass = Wizard;
                break;
            case 1:
                cout <<"n";
                chosenClass = Orc;
                break;
            case 2:
                chosenClass = Warrior;
                break;
            case 3:
                chosenClass = Rouge;
                break;
            default:
                cout << " out of bounds Class, nice try :)";
                exit(0);
        }
        cout << " " << playableClassAsString[chosenClass] << ". You cannot change class later, are you sure? (y/n)" << endl;
        std::string response;
        cin >> response;

        if(response == "y"){
            classIsNotDecided = false;
        }


    }

    return chosenClass;


}

Character CharacterCreator::createPlayerClass(playableClass characterClass, std::string characterName) {
    switch (characterClass){
        case Wizard: {
            Character character = Character(100, 5, std::move(characterName), "Wizard");
            character.addAttack(Attack(100, 5, "Fire ball"));
            character.addAttack(Attack(50, 3, "Water blast"));
            character.addAttack(Attack(80, 4, "Tangling roots"));
            character.addAttack(Attack(10, 0, "Air burst"));
            return character;
        }

        case Orc: {
            Character character = Character(300, 20, std::move(characterName), "Orc");
            character.addAttack(Attack(100, 5, "Cleave"));
            character.addAttack(Attack(50, 3, "Blood lust"));
            character.addAttack(Attack(80, 4, "Axe throw"));
            character.addAttack(Attack(10, 0, "Crush"));
            return character;
        }
        case Warrior: {
            Character character = Character(200, 30, std::move(characterName), "Warrior");
            character.addAttack(Attack(100, 5, "Stab"));
            character.addAttack(Attack(50, 3, "Slash"));
            character.addAttack(Attack(80, 4, "Kick"));
            character.addAttack(Attack(10, 0, "Punch"));
            return character;
            }
        case Rouge: {
            Character character = Character(100, 40, std::move(characterName), "Rouge");
            character.addAttack(Attack(100, 5, "Backstab"));
            character.addAttack(Attack(50, 3, "Blade fury"));
            character.addAttack(Attack(80, 4, "Bow shot"));
            character.addAttack(Attack(10, 0, "Sneak strike"));
            return character;
        }
    }

}

