#include "usableItem.h"

UsableItem::UsableItem(char c, string properName): Item{c, properName}{

}

UsableItem::~UsableItem(){
    
}

void UsableItem::onUse(Player& p){
    applyItemEffect(p);
    die();
}
