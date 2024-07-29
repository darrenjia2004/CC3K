#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "characters/character.h"
#include "tile.h"
class Item;

class Enemy : public Character {
    static const int enemyTeam = 1;
    const bool hasCompass;
    const int goldDrop;
    virtual void onDeath() override;
    // this is the item that the enemy unlocks on death
    Item* ownedItem;
    virtual bool isHostile();
public:
    virtual pair<bool,string> endOfTurnEffect(Tile& t) override;

    Enemy(char c, int maxHp, int atk, int def, bool hasCompass, int goldDrop, string properName, Item* ownedItem = nullptr);
    virtual pair<bool, string> move(Direction d, Tile& tile) override;
    bool attackHits() override;
};
#endif
