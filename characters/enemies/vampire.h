#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "characters/enemy.h"

class Vampire : public Enemy {
   public:
    static const char c;
    Vampire(bool hasCompass);
    char getChar();
};
#endif
