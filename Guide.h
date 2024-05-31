//
// Created by Tushant Man Singh on 31/5/2024.
//

#ifndef ZOORK_GUIDE_H
#define ZOORK_GUIDE_H
#include "Character.h"
#include <string>

class Guide : public Character {
public:
    Guide(const std::string& name, const std::string& description, const std::string& hint);
    void talk() override;
    std::string getHint() const;

private:
    std::string hint;
};

#endif //ZOORK_GUIDE_H
