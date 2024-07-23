#include "steppableItem.h"

SteppableItem::SteppableItem(char c, bool isUnlocked): Item{c, isUnlocked}{

}

SteppableItem::~SteppableItem(){
    
}

// void Item::onStepped(Player& p){
//     applyItemEffect(p);
//     die();
// }

// bool SteppableItem::isPassable(){
//     return (boss == null)
// }
