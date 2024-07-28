#include "player.h"
#include "enemy.h"
#include "items/steppableItem.h"
#include <cmath> //ceil
#include "items/usableItem.h"

Player::Player(char c, int maxHp, int atk, int def, string race): Character{c, maxHp, atk, def}, totGold{0}, race{race}, pfx{nullptr} {}

Player::~Player(){
    delete pfx;
}

void Player::applyPotion(Potionfx* p){
    p->next = pfx;
    pfx = p;
}

void Player::clearPotions(){
    delete pfx;
    pfx = nullptr;
}

int Player::getAttack(){
    return pfx ? Character::getAttack() + pfx->getAtkChange(): Character::getAttack();
}

int Player::getDefense(){
    // TODO: 100 if barrier suit
    return pfx ? Character::getDefense() + pfx->getDefChange(): Character::getDefense();
}

float Player::getGold(){
    return totGold;
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

pair<bool, string> Player::use(Direction d, Tile& tile){
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    Entity* targetEntity = target->getEntity();


    if (UsableItem* item = dynamic_cast<UsableItem*>(targetEntity)) {
        item->onUse(*this);
        return {true, "Player successfully used an item \n"};
    }

    return {false, "Player tried to use an item, but failed \n"};

}

pair<bool, string> Player::attack(Direction d, Tile& tile){
    if(!attackHits()){
        return make_pair(false, "Nothing to attack! \n");
    }

    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    Entity* targetEntity = target->getEntity();

    // if the target is a enemy then reduce enemy hp by current attack
    // kill the enemy if its health falls below 0
    if (Enemy* enemyPtr = dynamic_cast<Enemy*>(targetEntity)){
        enemyPtr->subtractFromHp(ceil((100.0/(100.0+enemyPtr->getDefense()))*getAttack()));
        enemyPtr->afterAttacked(*dynamic_cast<Character*>(this));
        if(enemyPtr->getHp() <= 0){
            enemyPtr->die();
        }
        return make_pair(true, "Player successfully attacked \n");
    }else{
        return make_pair(false, "Nothing to attack! \n");
    }
}

pair<bool, string> Player::move(Direction d, Tile& tile){
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    if(target->isPassable()){
        //cout << "target is passable" << endl;
        //the only passable tiles are those that are empty or have a steppable item on them. Technically if the entity exists we know its a steppable item but we check anyways
        Entity* targetEntity = target->getEntity();

        // check if empty or if its a steppable item
        if (targetEntity == nullptr){
            //cout << "entity is null" << endl;
        }
        else if(SteppableItem* sItemPtr = dynamic_cast<SteppableItem*>(targetEntity)){
            sItemPtr->onStepped(*this);
        }
        moveNoChecks(d, tile);
        return make_pair(true, "Player successfully moved \n");
    }
    else{
        return make_pair(false, "Player tried to move but failed \n");
    }
}

void Player::onDeath(){}
