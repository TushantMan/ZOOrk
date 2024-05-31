//
// Created by Richard Skarbez on 5/7/23.
//

#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, const std::string& description)
        : GameObject(name, description) {}

void Character::talk() {
    std::cout << "The character says nothing.\n";
}

void Character::addItem(std::shared_ptr<Item> item) {
    inventory.push_back(item);
}

void Character::removeItem(const std::string& itemName) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->getName() == itemName) {
            inventory.erase(it);
            break;
        }
    }
}

std::shared_ptr<Item> Character::getItem(const std::string& itemName) {
    for (const auto& item : inventory) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

void Character::displayInventory() {
    if (inventory.empty()) {
        std::cout << getName() << " has no items.\n";
    } else {
        std::cout << getName() << "'s inventory:\n";
        for (const auto& item : inventory) {
            std::cout << "- " << item->getName() << "\n";
        }
    }
}

