#include "item.h"

Item::Item(char c, string properName, bool isUnlocked): Entity{c, properName}, isUnlocked{isUnlocked}{

}

Item::~Item(){
    
}

void Item::unlock(){
    isUnlocked = true;
}

bool Item::getUnlocked(){
    return isUnlocked;
}
