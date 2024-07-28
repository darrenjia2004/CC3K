#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "characters/enemy.h"

class Merchant : public Enemy {
    static bool aggressive;
public:
    static const char c;
    Merchant(bool hasCompass);
    bool attackHits() override;
    void afterAttacked(Character& attacker) override;
    Entity* getLoot() override;
};
#endif
