# cmake_minimum_required(VERSION <specify CMake version here>)
project(arbeidskravCplusplus)

set(CMAKE_CXX_STANDARD 17)

add_executable(arbeidskravCplusplus main.cpp GameManager.cpp GameManager.h NameValidator.cpp NameValidator.h Character.cpp Character.h HP.cpp HP.h Attack.cpp Attack.h CharacterCreator.cpp CharacterCreator.h Formater.cpp Formater.h PlayerCharacter.cpp PlayerCharacter.h CharacterView.cpp CharacterView.h)