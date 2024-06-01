
#ifndef ZOORK_CHARACTER_H
#define ZOORK_CHARACTER_H

#include "GameObject.h"
#include "Item.h"
#include <vector>
#include <memory>
#include <string>

class Character : public GameObject {
public:
    Character(const std::string& name, const std::string& description);
    virtual ~Character() = default;
    virtual void talk();
    void addItem(std::shared_ptr<Item> item);
    void removeItem(const std::string& itemName);
    std::shared_ptr<Item> getItem(const std::string& itemName);
    void displayInventory();

protected:
    std::vector<std::shared_ptr<Item>> inventory;
};

#endif //ZOORK_CHARACTER_H
