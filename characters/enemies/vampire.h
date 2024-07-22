#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "characters/enemy.h"

class Vampire : public Enemy {
   public:
    Vampire(bool hasCompass) : Enemy{hasCompass, 1} {};
    char getChar() { return c; };
    static const char c;
};
#endif
