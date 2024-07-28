#include "characters/enemies/merchant.h"

const char Merchant::c = 'M';
bool Merchant::aggressive = false;

Merchant::Merchant(bool hasCompass) : Enemy{ 'M', 30, 70, 5, hasCompass, 0 } {}

bool Merchant::isAggressive(){
    return aggressive;
}

void Merchant::afterAttacked(Character& attacker){
    aggressive = true;
}