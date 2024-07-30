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

public:
    unique_ptr<Potionfx> pfx;
    Player(char c, int maxHp, int atk, int def, string race);
    virtual ~Player();
    virtual void applyPotion(int potionHp, int potionAtk, int potionDef);
    void clearPotions();
    virtual int getAttack() const override;
    virtual int getDefense() const override;
    int subtractFromHp(int n) override;
    float getGold() const;
    string getRace() const;
    virtual void increaseGold(float gold);
    void activateHpShrine();
    void activateStatsShrine();
    void gainCompass();
    void loseCompass();
    bool hasCompass() const;
    void gainBarrierSuit();
    virtual float calculateScore() const;
    void reset();
    virtual pair<bool, string> use(Direction d, Tile& tile);
    virtual pair<bool, string> move(Direction d, Tile& tile) override;
};

#endif
