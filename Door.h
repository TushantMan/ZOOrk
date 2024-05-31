//
// Created by Tushant Man Singh on 22/5/2024.
//

#ifndef ZOORK_DOOR_H
#define ZOORK_DOOR_H
#include "Passage.h"
#include "Item.h"

class Door : public Passage {
public:
    Door(const std::string& name, const std::string& description, Room* from, Room* to, const std::string& requiredItemName);

    void enter() override;

private:
    std::string requiredItemName;
};

#endif //ZOORK_DOOR_H
