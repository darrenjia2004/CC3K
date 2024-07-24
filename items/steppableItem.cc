#include "steppableItem.h"

SteppableItem::SteppableItem(char c, bool isUnlocked): Item{c, isUnlocked}{

}

SteppableItem::~SteppableItem(){
    
}

void SteppableItem::onStepped(Player& p){
    applyItemEffect(p);
    die();
}

bool SteppableItem::isPassable(){
    return getUnlocked();
}
