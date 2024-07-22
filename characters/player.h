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
    Potionfx* pfx;
    void onDeath();

   public:
    Player(char c, int maxHp, int atk, int def, int hp);
    void applyPotion(Potion* p);
    int getAttack();
    int getDefense();
    void increaseGold(float g);
    void gainCompass();
    void resetTempFx();
    void gainBarrierSuit();
    void calculateScore();
    void use(pair<int, int> pcoords, Tile& t);
};

#endif