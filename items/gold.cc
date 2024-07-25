#include "gold.h"

Gold::Gold(int goldValue, bool isUnlocked) : SteppableItem{ 'G', isUnlocked }, goldValue { goldValue } {

}

Gold::~Gold(){
    
}

void Gold::applyItemEffect(Player& p){
    p.increaseGold(goldValue);
}
