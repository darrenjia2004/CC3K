#include <memory>

#include "potion.h"
#include "gameModel.h"
#include "characters/potionfx.h"

Potion::Potion(int hp, int atk, int def, char c) : UsableItem{ c }, hp { hp }, atk{ atk }, def{ def } {

}

Potion::~Potion(){
    
}

void Potion::applyItemEffect(Player& p){
    GameModel::potionVisibility[c] = true;
    p.applyPotion(make_unique<Potionfx>(atk, def));

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
