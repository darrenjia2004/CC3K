#include "usableItem.h"

UsableItem::UsableItem(char c): Item{c}{

}

UsableItem::~UsableItem(){
    
}

void UsableItem::onUse(Player& p){
    applyItemEffect(p);
    die();
}
