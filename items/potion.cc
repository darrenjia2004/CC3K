#include "potion.h"
#include "gameModel.h"
#include "characters/potionfx.h"

Potion::Potion(int hp, int atk, int def, char c): hp{hp}, atk{atk}, def{def}, UsableItem{c}{

}

Potion::~Potion(){
    
}

void Potion::applyItemEffect(Player& p){
    GameModel::potionVisibility[c] = true;
    Potionfx* pfx = new Potionfx{atk, def};
    p.applyPotion(pfx);

    p.addToHp(hp);
}

char Potion::getChar(){
    if (GameModel::potionVisibility[c]){
        return c;
    }
    else{
        return 'P';
    }
}
