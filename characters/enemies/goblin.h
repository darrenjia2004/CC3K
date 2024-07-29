#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "characters/enemy.h"

class Goblin : public Enemy {
public:
    static const char c;
    Goblin(bool hasCompass);
    void afterAttacked(Character& attacker) override;
};
#endif
