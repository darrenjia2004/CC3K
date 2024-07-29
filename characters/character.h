#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "entity.h"
#include "tile.h"

class Character : public Entity {
    const int maxHp;
    int atk;
    int def;
    int hp;
protected:
    void moveNoChecks(Direction d, Tile& tile);
public:
    Character(char c, int maxHp, int atk, int def, int team,  string properName);
    const int team;
    int getHp();
    void addToHp(int n);
    virtual int subtractFromHp(int n);
    void addToStatsRandom();
    virtual int getAttack();
    virtual int getDefense();
    virtual bool attackHits();
    virtual pair<bool, string> attack(Direction d, Tile& tile);
    // move should return a bool indicating success and a string for what happened
    virtual pair<bool, string> move(Direction d, Tile& tile) = 0;
    virtual void afterAttacked(Character& attacker);
};
#endif
