#include "gold.h"

Gold::Gold(int goldValue): goldValue{goldValue}, SteppableItem{'g'}{

}

Gold::~Gold(){
    
}

// void Gold::applyItemEffect(Player& p){
//     p.increaseGold(goldValue);
// }