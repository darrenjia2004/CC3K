#include "steppableItem.h"

SteppableItem::SteppableItem(char c, string properName, bool isUnlocked): Item{c, properName, isUnlocked}{

}

SteppableItem::~SteppableItem(){
    
}

void SteppableItem::onStepped(Player& p){
    applyItemEffect(p);
    die();
}

bool SteppableItem::isPassable() const {
    return getUnlocked();
}
