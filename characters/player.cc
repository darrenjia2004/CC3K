#include "player.h"

Player::Player(char c, int maxHp, int atk, int def, int hp): Character{c, maxHp, atk, def}, hp{hp}{}

void Player::applyPotion(Potion* p){
    // adds a new potion effect to the linked list of potion effects
    Potionfx* newPfx = new Potionfx{p->atk, p->def};
    newPfx->next = pfx->next;
    pfx->next = newPfx;
}

int Player::getAttack(){
    return atk + pfx->getAtkChange();
}

int Player::getDefense(){
    return def + pfx->getDefChange();
}

float Player::getGold(){
    return totGold;
}

int Player::getHp(){
    return hp;
}

string Player::getRace(){
    return race;
}

void Player::increaseGold(float gold){
    totGold += gold;
}

void Player::gainCompass(){

}

void Player::resetTempFx(){
    delete pfx;
}

void Player::gainBarrierSuit(){

}

float Player::calculateScore(){
    return totGold;
}

void Player::use(pair<int, int> pcoords, Tile& t){
    
}

void Player::onDeath(){}
