#include "gold.h"

Gold::Gold(char c, int goldValue): goldValue{goldValue}, SteppableItem{c}{

}

Gold::~Gold(){
    
}

void Gold::applyItemEffect(Player& p){
    p.increaseGold(goldValue);
}
