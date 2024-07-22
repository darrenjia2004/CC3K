#ifndef _WEREWOLF_H_
#define _WEREWOLF_H_
#include "characters/enemy.h"

class Werewolf : public Enemy {
   public:
    static const char c;
    Werewolf(bool hasCompass);
    char getChar();
};
#endif
