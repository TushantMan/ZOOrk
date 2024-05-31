#include "RoomDefaultEnterCommand.h"
#include "Passage.h"
#include "HelpCommand.h"
#include "Room.h"
#include "ZOOrkEngine.h"
#include "Door.h"
#include "Guide.h"

// Define TreasureRoomEnterCommand class which inherits from Command class
class TreasureRoomEnterCommand : public Command {
public:
    explicit TreasureRoomEnterCommand(GameObject* g) : Command(g) {}

    void execute() override {
        std::cout << "Congratulations! You have found the treasure room!" << std::endl;
        std::cout << "Inside, you find a sparkling gem and a chest filled with gold." << std::endl;
        std::cout << "You have successfully completed your adventure. Well done!" << std::endl;
        std::cout << "Game over." << std::endl;
        exit(0);
    }
};

int main() {
    HelpCommand helpCommand;
    helpCommand.execute();
    std::shared_ptr<Room> start = std::make_shared<Room>("Start", "You are standing in an open field west of a white house, with a boarded front door.\n");
    std::shared_ptr<Room> south_of_house = std::make_shared<Room>("South of House", "You are facing the south side of a white house. There is no door here, and all the windows are barred.\n");
    std::shared_ptr<Room> behind_house = std::make_shared<Room>("Behind House", "You are behind the white house. A path leads into the forest to the east. In one corner of the house there is a small window which is slightly ajar.\n");

    // Forest area
    std::shared_ptr<Room> forest = std::make_shared<Room>("Forest", "You are in a dimly lit forest, with large trees all around.\n");
    std::shared_ptr<Room> forest_path = std::make_shared<Room>("Forest Path", "You are on a narrow path winding through the trees.\n");
    std::shared_ptr<Room> clearing = std::make_shared<Room>("Clearing", "You have entered a small clearing in the forest. There is a well in the center of the clearing.\n");

    // Mountain area
    std::shared_ptr<Room> mountain = std::make_shared<Room>("Mountain", "You are at the base of a large mountain. A steep trail leads upward.\n");
    std::shared_ptr<Room> mountain_trail = std::make_shared<Room>("Mountain Trail", "You are on a steep mountain trail. The air is thin and the view is breathtaking.\n");
    std::shared_ptr<Room> mountain_top = std::make_shared<Room>("Mountain Top", "You have reached the top of the mountain. You can see for miles in every direction.\n");

    // Cave area
    std::shared_ptr<Room> cave = std::make_shared<Room>("Cave", "You are standing at the mouth of a dark cave. A cold breeze emanates from within.\n");

    // Treasure room
    std::shared_ptr<Room> treasureRoom = std::make_shared<Room>("Treasure Room", "You have entered the treasure room. The room is filled with a golden glow.");
    treasureRoom->setEnterCommand(std::make_shared<TreasureRoomEnterCommand>(treasureRoom.get()));

    // Passages connecting the rooms
    Passage::createBasicPassage(start.get(), south_of_house.get(), "south", true);
    Passage::createBasicPassage(south_of_house.get(), behind_house.get(), "east", true);
    Passage::createBasicPassage(forest.get(), forest_path.get(), "east", true);
    Passage::createBasicPassage(clearing.get(), mountain.get(), "west", true);
    Passage::createBasicPassage(mountain.get(), mountain_trail.get(), "up", true);

    // Doors requiring specific items
    std::shared_ptr<Door> forestDoor = std::make_shared<Door>("Forest Door", "A dense forest that requires a sword to pass through.", behind_house.get(), forest.get(), "sword");
    behind_house->addPassage("east", forestDoor);
    forest->addPassage("west", forestDoor);

    std::shared_ptr<Door> clearingDoor = std::make_shared<Door>("Clearing Door", "A mystical clearing that requires a potion to enter.", forest_path.get(), clearing.get(), "potion");
    forest_path->addPassage("north", clearingDoor);
    clearing->addPassage("south", clearingDoor);

    std::shared_ptr<Door> mountainTopDoor = std::make_shared<Door>("Mountain Top Door", "A steep climb to the mountain top that requires a map.", mountain_trail.get(), mountain_top.get(), "map");
    mountain_trail->addPassage("up", mountainTopDoor);
    mountain_top->addPassage("down", mountainTopDoor);

    std::shared_ptr<Door> caveDoor = std::make_shared<Door>("Cave Door", "A locked door leading to the cave.", mountain_top.get(), cave.get(), "key");
    mountain_top->addPassage("north", caveDoor);
    cave->addPassage("south", caveDoor);

    std::shared_ptr<Door> treasureDoor = std::make_shared<Door>("Treasure Door", "A hidden door leading to the treasure room.", cave.get(), treasureRoom.get(), "gem");
    cave->addPassage("north", treasureDoor);
    treasureRoom->addPassage("south", treasureDoor);

    // Create some items
    std::shared_ptr<Item> key = std::make_shared<Item>("key", "A small, rusty key.");
    std::shared_ptr<Item> sword = std::make_shared<Item>("sword", "A shiny, sharp sword.");
    std::shared_ptr<Item> potion = std::make_shared<Item>("potion", "A vial containing a mysterious liquid.");
    std::shared_ptr<Item> map = std::make_shared<Item>("map", "An old, tattered map.");
    std::shared_ptr<Item> torch = std::make_shared<Item>("torch", "A flickering torch, providing light.");
    std::shared_ptr<Item> gem = std::make_shared<Item>("gem", "A sparkling, precious gemstone.");

    // Add items to rooms
    start->addItem(key);
    south_of_house->addItem(sword);
    behind_house->addItem(potion);
    forest->addItem(map);
    clearing->addItem(torch);
    mountain_top->addItem(gem);

    // Guide characters
    std::shared_ptr<Guide> startGuide = std::make_shared<Guide>("Guide", "A friendly guide welcoming you to the adventure.", "You're at the starting point. Explore the surroundings and find certain items to help you unlock progress.");
    std::shared_ptr<Guide> southOfHouseGuide = std::make_shared<Guide>("Guide", "A guide standing near the south side of the house.", "There seems to be some sharp object buried. Maybe you can find a sword somewhere.");
    std::shared_ptr<Guide> behindHouseGuide = std::make_shared<Guide>("Guide", "A guide hiding behind the house.", "There's a small window slightly ajar. Maybe you might be able to find some magical liquid bottle around.");
    std::shared_ptr<Guide> forestGuide = std::make_shared<Guide>("Guide", "A wise old man with knowledge of the forest.", "To navigate through the dense forest, you might need a map.");
    std::shared_ptr<Guide> forestPathGuide = std::make_shared<Guide>("Guide", "A guide wandering along the forest path.", "The narrow path winds through the trees. Stay alert for any clues or items.");
    std::shared_ptr<Guide> clearingGuide = std::make_shared<Guide>("Guide", "A guide resting in the clearing.", "The well in the center of the clearing might hold something valuable. A torch could help light your way.");
    std::shared_ptr<Guide> mountainGuide = std::make_shared<Guide>("Guide", "An experienced mountaineer who knows the mountain well.", "The mountain top is treacherous. Make sure you have the right equipment.");
    std::shared_ptr<Guide> mountainTrailGuide = std::make_shared<Guide>("Guide", "A guide hiking along the mountain trail.", "The view from the mountain trail is breathtaking. Keep an eye out for any hidden paths.");
    std::shared_ptr<Guide> mountainTopGuide = std::make_shared<Guide>("Guide", "A guide admiring the view from the mountain top.", "You've reached the summit. The cave entrance lies ahead, but it seems to be locked. A key from past is your way. A gem might also be hidden somewhere that might help in your dark times.");
    std::shared_ptr<Guide> caveGuide = std::make_shared<Guide>("Guide", "A guide exploring the cave.", "The cave is dark and chilly. A gem might be needed to unlock the door.");

    // Add guide characters to each room
    start->addCharacter(startGuide);
    south_of_house->addCharacter(southOfHouseGuide);
    behind_house->addCharacter(behindHouseGuide);
    forest->addCharacter(forestGuide);
    forest_path->addCharacter(forestPathGuide);
    clearing->addCharacter(clearingGuide);
    mountain->addCharacter(mountainGuide);
    mountain_trail->addCharacter(mountainTrailGuide);
    mountain_top->addCharacter(mountainTopGuide);
    cave->addCharacter(caveGuide);

    ZOOrkEngine zoork(start);
    zoork.run();

    return 0;
}