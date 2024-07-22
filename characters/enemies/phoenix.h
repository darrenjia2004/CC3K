#ifndef _PHOENIX_H_
#define _PHOENIX_H_
#include "characters/enemy.h"

class Phoenix : public Enemy {
   public:
    static const char c;
    Phoenix(bool hasCompass);
    char getChar();
};
#endif
