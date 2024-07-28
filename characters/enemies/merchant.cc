#include "characters/enemies/merchant.h"
#include "items/gold.h"

const char Merchant::c = 'M';
bool Merchant::aggressive = false;

Merchant::Merchant(bool hasCompass) : Enemy{ 'M', 30, 70, 5, hasCompass, 0 } {}

bool Merchant::attackHits(){
    return aggressive;
}

void Merchant::afterAttacked(Character& attacker){
    aggressive = true;
}

Entity* Merchant::getLoot(){
    return new Gold{ 4 };
}