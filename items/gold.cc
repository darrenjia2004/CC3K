#include "gold.h"

Gold::Gold(int goldValue, bool isUnlocked): goldValue{goldValue}, SteppableItem{'G', isUnlocked}{

}

Gold::~Gold(){
    
}

void Gold::applyItemEffect(Player& p){
    p.increaseGold(goldValue);
}
