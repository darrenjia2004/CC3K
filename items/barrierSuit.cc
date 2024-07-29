#include "barrierSuit.h"

BarrierSuit::BarrierSuit(bool isUnlocked): SteppableItem{'B', "BarrierSuit", isUnlocked}{

}

BarrierSuit::~BarrierSuit(){
    
}

void BarrierSuit::applyItemEffect(Player& p){
    p.gainBarrierSuit();
}
