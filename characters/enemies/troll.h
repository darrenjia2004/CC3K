#ifndef _TROLL_H_
#define _TROLL_H_
#include "characters/enemy.h"

class Troll : public Enemy {
   public:
    Troll(bool hasCompass) : Enemy{hasCompass, 1} {};
    char getChar() { return c; };
    static const char c;
};
#endif
