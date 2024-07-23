#include "gold.h"

Gold::Gold(char c, int goldValue, bool isUnlocked): goldValue{goldValue}, SteppableItem{c, isUnlocked}{

}

Gold::~Gold(){
    
}

void Gold::applyItemEffect(Player& p){
    p.increaseGold(goldValue);
}
