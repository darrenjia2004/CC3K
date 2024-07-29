#include "compass.h"

Compass::Compass(): SteppableItem{'C'}{}

Compass::~Compass(){
    
}

void Compass::applyItemEffect(Player& p){
    p.gainCompass();
}
