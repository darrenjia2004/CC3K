#include "characters/enemies/merchant.h"
#include "items/gold.h"

const char Merchant::c = 'M';
bool Merchant::aggressive = false;

Merchant::Merchant(bool hasCompass) : Enemy{ 'M', 30, 70, 5, hasCompass, 0 , "Merchant"} {}

bool Merchant::isHostile() const {
    return aggressive;
}

void Merchant::afterAttacked(Character& attacker){
    Enemy::afterAttacked(attacker);
    aggressive = true;
}

Entity* Merchant::getLoot() const {
    return new Gold{ 4 };
}