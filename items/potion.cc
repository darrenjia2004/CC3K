#include <memory>

#include "potion.h"
#include "characters/potionfx.h"

unordered_map<char, bool> Potion::potionVisibility;

Potion::Potion(int hp, int atk, int def, char c, string properName) : UsableItem{ c, properName }, hp { hp }, atk{ atk }, def{ def } {

}

Potion::~Potion(){
    
}

void Potion::applyItemEffect(Player& p){
    potionVisibility[c] = true;
    p.applyPotion(hp, atk, def);
}

char Potion::getChar() const {
    if (potionVisibility[c]){
        return c;
    }
    else{
        return 'P';
    }
}

void Potion::resetVisibility(){
    potionVisibility = unordered_map<char, bool>();
}
