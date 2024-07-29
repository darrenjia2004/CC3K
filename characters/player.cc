#include "player.h"
#include "enemy.h"
#include "items/steppableItem.h"
#include <cmath> //ceil
#include "items/usableItem.h"

Player::Player(char c, int maxHp, int atk, int def, string race) : 
    Character{ c, maxHp, atk, def, playerTeam, "PC" }, totGold{ 0 }, 
    race{ race }, hasBarrierSuit{ false }, pfx{ unique_ptr<Potionfx>{nullptr} } {}

Player::~Player(){
}

void Player::applyPotion(unique_ptr<Potionfx> p){
    p->next = std::move(pfx);
    pfx = std::move(p);
}

void Player::clearPotions(){
    pfx = unique_ptr<Potionfx>{nullptr};
}

int Player::getAttack() const {
    return pfx ? Character::getAttack() + pfx->getAtkChange(): Character::getAttack();
}

int Player::getDefense()const {
    // TODO: 100 if barrier suit
    return pfx ? Character::getDefense() + pfx->getDefChange(): Character::getDefense();
}

float Player::getGold() const {
    return totGold;
}

string Player::getRace() const {
    return race;
}

void Player::increaseGold(float gold){
    totGold += gold;
}

int Player::subtractFromHp(int n){
    if(hasBarrierSuit){
        int modified{ceil(n / 2.0)};
        return Character::subtractFromHp(modified);
    }
    else{
        return Character::subtractFromHp(n);
    }        
}

void Player::gainCompass(){
    compassAcquired = true;
}

bool Player::hasCompass() const {
    return compassAcquired;
}

void Player::loseCompass(){
    compassAcquired = false;
}

void Player::gainBarrierSuit(){
    hasBarrierSuit = true;
}

float Player::calculateScore() const{
    return totGold;
}

pair<bool, string> Player::use(Direction d, Tile& tile){
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    Entity* targetEntity = target->getEntity();
    string name = getProperName();

    if (UsableItem* item = dynamic_cast<UsableItem*>(targetEntity)) {
        string targetName = item->getProperName();
        item->onUse(*this);
        return {true, name + " used " + targetName + " \n"};
    }

    return {false, name + " tried to use an item, but failed \n"};

}

pair<bool, string> Player::move(Direction d, Tile& tile){
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    string name = getProperName();
    if(target->isPassable()){
        //cout << "target is passable" << endl;
        //the only passable tiles are those that are empty or have a steppable item on them. Technically if the entity exists we know its a steppable item but we check anyways
        Entity* targetEntity = target->getEntity();

        string steppedString = "";
        // check if empty or if its a steppable item
        if (targetEntity == nullptr){
            //cout << "entity is null" << endl;
        }
        else if(SteppableItem* sItemPtr = dynamic_cast<SteppableItem*>(targetEntity)){
            steppedString = " and picked up " + sItemPtr->getProperName();
            sItemPtr->onStepped(*this);
        }
        moveNoChecks(d, tile);
        return make_pair(true, name + " moved " + getDirectionName(d) + steppedString + "\n");
    }
    else{
        return make_pair(false, name + " tried to move " + getDirectionName(d) + " but failed \n");
    }
}

void Player::onDeath(){}
