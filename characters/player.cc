#include "player.h"
#include "items/steppableItem.h"
#include "items/usableItem.h"

Player::Player(char c, int maxHp, int atk, int def, int hp): Character{c, maxHp, atk, def}, hp{hp}{}

void Player::applyPotion(Potionfx* p){
    p->next = pfx;
    pfx = p;
}

int Player::getAttack(){
    return pfx ? max(atk + pfx->getAtkChange(), 0): atk;
}

int Player::getDefense(){
    return pfx ? max(def + pfx->getDefChange(), 0): def;
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

void Player::attack(Direction d, Tile& tile){}
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