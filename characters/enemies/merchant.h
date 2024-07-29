#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "characters/enemy.h"

class Merchant : public Enemy {
    static bool aggressive;
    virtual bool isHostile() override;
public:
    static const char c;
    Merchant(bool hasCompass);
    void afterAttacked(Character& attacker) override;
    Entity* getLoot() override;
};
#endif
