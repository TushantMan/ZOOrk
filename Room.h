
#ifndef ZOORK_ROOM_H
#define ZOORK_ROOM_H

#include "Character.h"
#include "RoomDefaultEnterCommand.h"
#include "Item.h"
#include "Location.h"
#include <map>

class Passage;

class Room : public Location {
public:
    Room(const std::string &, const std::string &);
    Room(const std::string &, const std::string &, std::shared_ptr<Command>);
    void addItem(std::shared_ptr<Item> item);
    void removeItem(const std::string& itemName);
    std::shared_ptr<Item> getItem(const std::string& itemName);
    void addCharacter(std::shared_ptr<Character> character);
    std::shared_ptr<Character> getCharacter(const std::string& name);
    void addPassage(const std::string &, std::shared_ptr<Passage>);
    void removePassage(const std::string &);
    std::shared_ptr<Passage> getPassage(const std::string &);

private:
    std::vector<std::shared_ptr<Item>> items;
    std::vector<std::shared_ptr<Character>> characters;
    std::map<std::string, std::shared_ptr<Passage>> passageMap;
};

#endif //ZOORK_ROOM_H
