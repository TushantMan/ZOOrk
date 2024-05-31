//
// Created by Tushant Man Singh on 22/5/2024.
//
#include "Door.h"
#include "Player.h"

Door::Door(const std::string& name, const std::string& description, Room* from, Room* to, const std::string& requiredItemName)
        : Passage(name, description, from, to), requiredItemName(requiredItemName) {}

void Door::enter() {
    Player* player = Player::instance();
    std::shared_ptr<Item> requiredItem = player->getItem(requiredItemName);

    if (requiredItem != nullptr) {
        std::cout << "You use the " << requiredItemName << " to open the door." << std::endl;
        Passage::enter();
    } else {
        std::cout << "The door is locked. You need a " << requiredItemName << " to open it." << std::endl;
    }
}