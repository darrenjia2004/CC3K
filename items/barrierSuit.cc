#include "barrierSuit.h"

BarrierSuit::BarrierSuit(bool isUnlocked): SteppableItem{c, isUnlocked}{

}

BarrierSuit::~BarrierSuit(){
    
}

void BarrierSuit::applyItemEffect(Player& p){
    p.gainBarrierSuit();
}
