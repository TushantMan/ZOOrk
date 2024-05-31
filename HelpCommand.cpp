//
// Created by Tushant Man Singh on 31/5/2024.
//
#include "HelpCommand.h"
#include <iostream>

void HelpCommand::execute() {
    std::cout << "Available commands:\n";
    std::cout << "- go <direction>: Move in the specified direction (e.g., go north, go east).\n";
    std::cout << "- look/inspect: Examine the current room or an item.\n";
    std::cout << "- take/get <item>: Pick up an item from the room.\n";
    std::cout << "- drop <item>: Drop an item from your inventory.\n";
    std::cout << "- inventory/inv/i: Check your inventory.\n";
    std::cout << "- ask guide: Ask the guide in the current room for a hint.\n";
    std::cout << "- quit: Quit the game.\n";
    std::cout << "\n";
    std::cout << "Available items:\n";
    std::cout << "- key: A small, rusty key.\n";
    std::cout << "- sword: A shiny, sharp sword.\n";
    std::cout << "- potion: A vial containing a mysterious liquid.\n";
    std::cout << "- map: An old, tattered map.\n";
    std::cout << "- torch: A flickering torch, providing light.\n";
    std::cout << "- gem: A sparkling, precious gemstone.\n";
    std::cout << std::endl;
}