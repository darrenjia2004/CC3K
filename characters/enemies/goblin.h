#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "characters/enemy.h"

class Goblin : public Enemy {
   public:
    static const char c;
    Goblin(bool hasCompass) : Enemy{hasCompass, 1} {};
    char getChar() { return c; };
};
#endif
