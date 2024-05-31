//
// Created by Richard Skarbez on 5/7/23.
//

#include "NullPassage.h"
#include "Room.h"

#include <utility>


Room::Room(const std::string &n, const std::string &d) : Location(n, d) {
    enterCommand = std::make_shared<RoomDefaultEnterCommand>(this);
}
Room::Room(const std::string &n, const std::string &d, std::shared_ptr<Command> c) : Location(n, d, std::move(c)) {}
void Room::addPassage(const std::string &direction, std::shared_ptr<Passage> p) {
    passageMap[direction] = std::move(p);
}
void Room::removePassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        passageMap.erase(direction);
    }
}
std::shared_ptr<Passage> Room::getPassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        return passageMap[direction];
    } else {
        std::cout << "It is impossible to go " << direction << "!\n";
        return std::make_shared<NullPassage>(this);
    }
}
void Room::addItem(std::shared_ptr<Item> item) {
    items.push_back(item);
}
void Room::removeItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {
            items.erase(it);
            break;
        }
    }
}
void Room::addCharacter(std::shared_ptr<Character> character) {
    characters.push_back(character);
}
std::shared_ptr<Character> Room::getCharacter(const std::string& name) {
    for (const auto& character : characters) {
        if (character->getName() == name) {
            return character;
        }
    }
    return nullptr;
}
std::shared_ptr<Item> Room::getItem(const std::string& itemName) {
    for (const auto& item : items) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}