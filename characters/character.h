#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "entity.h"
#include "tile.h"

class Character : public Entity {
    const int maxHp;
    const int atk;
    const int def;
    int hp;

public:
    Character(char c, int maxHp, int atk, int def);
    int getHp();
    void addToHp(int n);
    void subtractFromHp(int n);

    virtual void attack(Direction d, Tile& tile) = 0;
    virtual void move(Direction d, Tile& tile) = 0;
};
#endif