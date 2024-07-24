#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "characters/character.h"
#include "tile.h"
#include "potionfx.h"

using namespace std;

class Player : public Character {
    int hp;
    int maxHp;
    int atk;
    int def;
    float totGold;
    string race;
    virtual void onDeath();

public:
    Potionfx* pfx;
    Player(char c, int maxHp, int atk, int def, int hp);
    virtual void applyPotion(Potionfx* p);
    int getAttack();
    int getDefense();
    float getGold();
    int getHp();
    virtual string getRace();
    virtual void increaseGold(float gold);
    void gainCompass();
    void resetTempFx();
    void gainBarrierSuit();
    virtual float calculateScore();
    pair<bool, string> use(Direction d, Tile& tile);
    virtual void attack(Direction d, Tile& tile) override;
    virtual pair<bool, string> move(Direction d, Tile& tile) override;
};

#endif
