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
    virtual void onDeath();

   public:
    Potionfx* pfx;
    Player(char c, int maxHp, int atk, int def, int hp);
    virtual void applyPotion(Potion* p);
    int getAttack();
    int getDefense();
    float getGold();
    int getHp();
    virtual string getRace();
    void increaseGold(float gold);
    void gainCompass();
    void resetTempFx();
    void gainBarrierSuit();
    virtual float calculateScore();
    void use(pair<int, int> pcoords, Tile& t);
};

#endif
