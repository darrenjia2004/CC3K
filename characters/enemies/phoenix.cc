#include "characters/enemies/phoenix.h"

Phoenix::Phoenix(bool hasCompass, int regenCount) : 
    Enemy{ 'X', 50 / regenCount, 35, 20, hasCompass, 1 , "Phoenix"}, regenCount{regenCount} {}

Entity* Phoenix::getLoot() const {
    if(regenCount >= maxRegens){
        return Enemy::getLoot();
    }

    Phoenix * p = new Phoenix{hasCompass(), regenCount + 1};
    p->setHasDoneEndOfTurn(true); //make sure phoenix can't attack after it's born

    return p;
}