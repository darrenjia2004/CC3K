#ifndef _DRAGON_H_
#define _DRAGON_H_
#include "characters/enemy.h"

class Dragon : public Enemy {
public:
    static const char c;
    Dragon(bool hasCompass, Item* ownedItem);
public:
    pair<bool, string> move(Direction d, Tile& t);
};
#endif
