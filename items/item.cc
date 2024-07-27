#include "item.h"

Item::Item(char c, bool isUnlocked): Entity{c}, isUnlocked{isUnlocked}{

}

Item::~Item(){
    
}

void Item::unlock(){
    isUnlocked = true;
}

bool Item::getUnlocked(){
    return isUnlocked;
}
