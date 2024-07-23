#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "characters/character.h"
#include "tile.h"
#include "potionfx.h"
#include "items/potion.h"

using namespace std;

class Player : public Character {
    int hp;
    int maxHp;
    int atk;
    int def; 
    float gold;
    string race;
    Potionfx* pfx;
    virtual void onDeath();

   public:
    Player(char c, int maxHp, int atk, int def, int hp);
    void applyPotion(Potion* p);
    int getAttack();
    int getDefense();
    float getGold();
    int getHp();
    string getRace();
    void increaseGold(float gold);
    void gainCompass();
    void resetTempFx();
    void gainBarrierSuit();
    void calculateScore();
    void use(pair<int, int> pcoords, Tile& t);
};

#endif