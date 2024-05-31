//
// Created by Tushant Man Singh on 31/5/2024.
//
#include "Guide.h"
#include <iostream>

Guide::Guide(const std::string& name, const std::string& description, const std::string& hint)
        : Character(name, description), hint(hint) {}

void Guide::talk() {
    std::cout << "The guide says, 'Hello, adventurer! Here's a hint for you: " << hint << "'\n";
}

std::string Guide::getHint() const {
    return hint;
}