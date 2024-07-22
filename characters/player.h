#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "characters/character.h"
#include "tile.h"
#include "potionfx.h"
#include "items/potion.h"

class Player : public Character {
    int hp;
    int maxHp;
    int atk;
    int def; 
    int initAtk;
    int initDef;
    Potionfx* pfx;
    void onDeath();

   public:
    Player(int hp, int maxHp, int atk, int def, Potionfx* pfx);
    void applyPotion(Potion& p);
    void increaseGold(float g);
    void gainCompass();
    void resetTempFx();
    void gainBarrierSuit();
    void calculateScore();
    void use(pair<int, int> pcoords, Tile& t);
};

#endif