
#include "ZOOrkEngine.h"

#include <utility>

ZOOrkEngine::ZOOrkEngine(std::shared_ptr<Room> start) {
    player = Player::instance();
    player->setCurrentRoom(start.get());
    player->getCurrentRoom()->enter();
}

void ZOOrkEngine::run() {
    while (!gameOver) {
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> words = tokenizeString(input);
        std::string command = words[0];
        std::vector<std::string> arguments(words.begin() + 1, words.end());

        if (command == "go") {
            handleGoCommand(arguments);
        } else if (command == "look" || command == "inspect") {
            handleLookCommand(arguments);
        } else if (command == "take" || command == "get") {
            handleTakeCommand(arguments);
        } else if (command == "drop") {
            handleDropCommand(arguments);
        } else if (command == "ask" && arguments.size() == 1 && arguments[0] == "guide") {
            handleAskGuideCommand();
        } else if (command == "inventory" || command == "inv" || command == "i") {
            Player::instance()->displayInventory();
        } else if (command == "quit") {
            handleQuitCommand(arguments);
        } else {
            std::cout << "I don't understand that command.\n";
        }
    }
}

void ZOOrkEngine::handleGoCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Go where?\n";
        return;
    }

    std::string direction;
    if (arguments[0] == "n" || arguments[0] == "north") {
        direction = "north";
    } else if (arguments[0] == "s" || arguments[0] == "south") {
        direction = "south";
    } else if (arguments[0] == "e" || arguments[0] == "east") {
        direction = "east";
    } else if (arguments[0] == "w" || arguments[0] == "west") {
        direction = "west";
    } else if (arguments[0] == "u" || arguments[0] == "up") {
        direction = "up";
    } else if (arguments[0] == "d" || arguments[0] == "down") {
        direction = "down";
    } else {
        direction = arguments[0];
    }

    Room* currentRoom = Player::instance()->getCurrentRoom();
    auto passage = currentRoom->getPassage(direction);
    if (passage != nullptr) {
        Player::instance()->setCurrentRoom(passage->getTo());
        passage->enter();
    } else {
        std::cout << "There is no way to go " << direction << ".\n";
    }
}

void ZOOrkEngine::handleLookCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        // If no arguments are provided, describe the current room
        std::cout << player->getCurrentRoom()->getDescription() << "\n";
    } else {
        std::string target = arguments[0];

        // Check if the target is an item in the room
        // (Assuming you have implemented the getItem() method in the Room class)
        std::shared_ptr<Item> item = player->getCurrentRoom()->getItem(target);
        if (item != nullptr) {
            std::cout << item->getDescription() << "\n";
            return;
        }

        // Check if the target is a character in the room
        // (Assuming you have implemented the getCharacter() method in the Room class)
        std::shared_ptr<Character> character = player->getCurrentRoom()->getCharacter(target);
        if (character != nullptr) {
            std::cout << character->getDescription() << "\n";
            return;
        }

        // Check if the target is a passage in the room
        std::shared_ptr<Passage> passage = player->getCurrentRoom()->getPassage(target);
        if (passage != nullptr) {
            std::cout << passage->getDescription() << "\n";
            return;
        }

        // If the target is not found, display an appropriate message
        std::cout << "You don't see " << target << " here.\n";
    }
}

void ZOOrkEngine::handleTakeCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Take what?\n";
    } else {
        std::string itemName = arguments[0];
        std::shared_ptr<Item> item = player->getCurrentRoom()->getItem(itemName);
        if (item != nullptr) {
            player->addItem(item);
            player->getCurrentRoom()->removeItem(itemName);
            std::cout << "You take the " << itemName << ".\n";
        } else {
            std::cout << "There is no " << itemName << " here.\n";
        }
    }
}
void ZOOrkEngine::handleAskGuideCommand() {
    Room* currentRoom = Player::instance()->getCurrentRoom();
    std::shared_ptr<Character> guide = currentRoom->getCharacter("Guide");
    if (guide != nullptr) {
        std::shared_ptr<Guide> roomGuide = std::dynamic_pointer_cast<Guide>(guide);
        if (roomGuide != nullptr) {
            std::cout << roomGuide->getHint() << "\n";
        }
    } else {
        std::cout << "There is no guide in this room.\n";
    }
}
void ZOOrkEngine::handleDropCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Drop what?\n";
    } else {
        std::string itemName = arguments[0];
        std::shared_ptr<Item> item = player->getItem(itemName);
        if (item != nullptr) {
            player->removeItem(itemName);
            player->getCurrentRoom()->addItem(item);
            std::cout << "You drop the " << itemName << ".\n";
        } else {
            std::cout << "You don't have a " << itemName << ".\n";
        }
    }
}

void ZOOrkEngine::handleQuitCommand(std::vector<std::string> arguments) {
    std::string input;
    std::cout << "Are you sure you want to QUIT?\n> ";
    std::cin >> input;
    std::string quitStr = makeLowercase(input);

    if (quitStr == "y" || quitStr == "yes") {
        gameOver = true;
    }
}

std::vector<std::string> ZOOrkEngine::tokenizeString(const std::string &input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' ')) {
        tokens.push_back(makeLowercase(token));
    }

    return tokens;
}

std::string ZOOrkEngine::makeLowercase(std::string input) {
    std::string output = std::move(input);
    std::transform(output.begin(), output.end(), output.begin(), ::tolower);

    return output;
}
