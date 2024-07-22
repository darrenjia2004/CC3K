#ifndef _PHOENIX_H_
#define _PHOENIX_H_
#include "characters/enemy.h"

class Phoenix : public Enemy {
   public:
    Phoenix(bool hasCompass) : Enemy{hasCompass, 1} {};
    char getChar() { return c; };
    static const char c;
};
#endif
