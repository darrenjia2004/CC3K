#include "potion.h"

Potion::Potion(int hp, int atk, int def, char c): hp{hp}, atk{atk}, def{def}, UsableItem{c}{

}

Potion::~Potion(){
    
}

// void Potion::applyItemEffect(Player& p){
//     p.applyPotion(*this);
// }

char Potion::getChar(){
    if (GameModel::potionVisibility[c]){
        return c;
    }
    else{
        return 'P';
    }
}