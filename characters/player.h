#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "characters/character.h"
#include "tile.h"
#include "potionfx.h"

using namespace std;

class Player : public Character {
    static const int playerTeam = 0;
    float totGold;
    const string race;
    bool compassAcquired = false;
    bool hasBarrierSuit;
    virtual void onDeath();

public:
    unique_ptr<Potionfx> pfx;
    Player(char c, int maxHp, int atk, int def, string race);
    virtual ~Player();
    virtual void applyPotion(unique_ptr<Potionfx> p);
    void clearPotions();
    virtual int getAttack() override;
    virtual int getDefense() override;
    int subtractFromHp(int n) override;
    float getGold();
    string getRace();
    virtual void increaseGold(float gold);
    void gainCompass();
    bool hasCompass();
    void resetTempFx();
    void gainBarrierSuit();
    virtual float calculateScore();
    virtual pair<bool, string> use(Direction d, Tile& tile);
    virtual pair<bool, string> move(Direction d, Tile& tile) override;
};

#endif
