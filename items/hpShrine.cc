#include "items/hpShrine.h"

HpShrine::HpShrine(): UsableItem{'H', "HP Shrine"}{
    
}

HpShrine::~HpShrine(){
    
}

void HpShrine::applyItemEffect(Player& p){
    p.activateHpShrine();
    
}

void HpShrine::onUse(Player& p){
    if(p.getGold() >= 1){
        applyItemEffect(p);
    }
}
 