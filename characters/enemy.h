#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "characters/character.h"
#include "tile.h";

class Enemy : public Character {
    const bool hasCompass;
    const int goldDrop;
    void onDeath();

   public:
    void endOfTurnEffect(Tile& t);

    Enemy(bool hasCompass, int goldDrop);
};
#endif