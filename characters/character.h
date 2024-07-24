#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "entity.h"
#include "tile.h"

class Character : public Entity {
    const int maxHp;
    const int atk;
    const int def;
    int hp;
protected:
    void moveNoChecks(Direction d, Tile& tile);
public:
    Character(char c, int maxHp, int atk, int def);
    int getHp();
    void addToHp(int n);
    void subtractFromHp(int n);

    virtual void attack(Direction d, Tile& tile) = 0;
    // move should return a bool indicating success and a string for what happened
    virtual pair<bool, string> move(Direction d, Tile& tile) = 0;
};
#endif
