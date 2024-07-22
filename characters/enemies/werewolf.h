#ifndef _WEREWOLF_H_
#define _WEREWOLF_H_
#include "characters/enemy.h"

class Werewolf : public Enemy {
   public:
    Werewolf(bool hasCompass) : Enemy{hasCompass, 1} {};
    char getChar() { return c; };
    static const char c;
};
#endif
