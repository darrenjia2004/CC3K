#ifndef _TROLL_H_
#define _TROLL_H_
#include "characters/enemy.h"

class Troll : public Enemy {
   public:
    static const char c;
    Troll(bool hasCompass);
    char getChar();
};
#endif
