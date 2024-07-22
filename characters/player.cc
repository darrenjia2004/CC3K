#include "player.h"

Player::Player(char c, int maxHp, int atk, int def, int hp): Character{c, maxHp, atk, def}, hp{hp}{}

void Player::applyPotion(Potion* p){
    Potionfx* newPfx = new Potionfx{p->atk, p->def};
    newPfx->next = pfx->next;
    pfx->next = newPfx;
}

int Player::getAttack(){
    int currAtk = atk;
    while(nullptr != pfx->next){
        currAtk += pfx->getAtkChange();
        pfx = pfx->next;
    }
    return currAtk;
}

int Player::getDefense(){
    int currDef = def;
    while(nullptr != pfx->next){
        currDef += pfx->getDefChange();
        pfx = pfx->next;
    }
    return currDef;
}

void Player::increaseGold(float g){

}

void Player::gainCompass(){

}

void Player::resetTempFx(){

}

void Player::gainBarrierSuit(){

}

void Player::calculateScore(){

}

void Player::use(pair<int, int> pcoords, Tile& t){
    
}
