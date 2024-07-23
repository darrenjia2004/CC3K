#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "characters/character.h"
#include "tile.h"
class Item;

class Enemy : public Character {
    const bool hasCompass;
    const int goldDrop;
    virtual void onDeath() override;
    // this is the item that the enemy unlocks on death
    Item* ownedItem;

public:
    void endOfTurnEffect(Tile& t);

    Enemy(char c, int maxHp, int atk, int def, bool hasCompass, int goldDrop, Item* ownedItem = nullptr);
    void attack(Direction d, Tile& tile);
    void move(Direction d, Tile& tile);
};
#endif