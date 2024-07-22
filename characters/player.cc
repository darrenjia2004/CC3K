#include "player.h"

Player::Player(int maxHp, int atk, int def, Potionfx* pfx): Character{maxHp, atk, def}, pfx{pfx} {}

void applyPotion(Potion& p){
    Potionfx* newPfx = new Potionfx{p->atk, p->def};
    newPfx->next = pfx->next;
    pfx->next = newPfx;
}

int getAttack(){
    int currAtk = atk;
    while(nullptr != pfx->next){
        currAtk += getAtkChange();
        p = p->next;
    }
    return currAtk;
}

void getDefense(){
    int currDef = def;
    while(nullptr != pfx->next){
        currDef += getDefChange();
        p = p->next;
    }
    return currDef;

}
void increaseGold(float g){

}

void gainCompass(){

}

void resetTempFx(){

}

void gainBarrierSuit(){

}

void calculateScore(){

}

void use(pair<int> pcoords, Tile& t){
    
}
