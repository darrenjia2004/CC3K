#include "barrierSuit.h"

BarrierSuit::BarrierSuit(bool isUnlocked): SteppableItem{'B', isUnlocked}{

}

BarrierSuit::~BarrierSuit(){
    
}

void BarrierSuit::applyItemEffect(Player& p){
    p.gainBarrierSuit();
}
