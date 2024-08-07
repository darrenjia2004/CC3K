#ifndef _DRAGON_H_
#define _DRAGON_H_
#include "characters/enemy.h"

class Dragon : public Enemy {
public:
    static const char c;
    Dragon(bool hasCompass, Tile* ownedItemTile);
    pair<bool, string> attack(Direction d, Tile& t) override;
    pair<bool, string> move(Direction d, Tile& t);
};
#endif
