#include "player.h"

Player::Player(char c, int maxHp, int atk, int def, int hp): Character{c, maxHp, atk, def}, hp{hp}{}

void Player::applyPotion(Potionfx* p){
    p->next = pfx;
    pfx = p;
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

void Player::attack(Direction d, Tile& tile){}
void Player::move(Direction d, Tile& tile){}

void Player::onDeath(){}