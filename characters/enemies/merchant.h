#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "characters/enemy.h"

class Merchant : public Enemy {
   public:
    static const char c;
    Merchant(bool hasCompass);
    char getChar();
};
#endif
