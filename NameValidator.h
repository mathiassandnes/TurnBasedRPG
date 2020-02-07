//
// Created by mathi on 2/7/2020.
//

#ifndef ARBEIDSKRAVCPLUSPLUS_NAMEVALIDATOR_H
#define ARBEIDSKRAVCPLUSPLUS_NAMEVALIDATOR_H


#include <string>
#include <set>

class NameValidator {
public:
    static bool isNameTaken(const std::string& name, const std::set<std::string>& names);
};


#endif //ARBEIDSKRAVCPLUSPLUS_NAMEVALIDATOR_H
