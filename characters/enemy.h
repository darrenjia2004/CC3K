#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"
#include "tile.h"

class Enemy : public Character {
    static const int enemyTeam = 1;
    bool compass;
    const int goldDrop;
    virtual void onDeath() override;
    // this is the item that the enemy unlocks on death
    Tile* ownedItemTile;
    virtual bool isHostile();
public:
    virtual pair<bool,string> endOfTurnEffect(Tile& t) override;

    Enemy(char c, int maxHp, int atk, int def, bool hasCompass, int goldDrop,  string properName, Tile* ownedItem = nullptr);
    virtual pair<bool, string> move(Direction d, Tile& tile) override;
    bool attackHits() override;
    virtual Entity* getLoot() override;
    Tile* getOwnedItemTile();
    void gainCompass();
    bool hasCompass();
};
#endif
