#include "characters/enemy.h"
#include "items/item.h"
#include <cmath>     // ceil
#include <stdlib.h>  // srand/rand
#include "command.h"

Enemy::Enemy(char c, int maxHp, int atk, int def, bool hasCompass, int goldDrop, Item* ownedItem) 
: Character{ c, maxHp, atk, def }, hasCompass{ hasCompass }, goldDrop{ goldDrop }, ownedItem{ownedItem} {}

// TODO fill these in
void Enemy::onDeath() {
    if (ownedItem){
        ownedItem->unlock();
    }
}

pair<bool,string> Enemy::endOfTurnEffect(Tile& t) {
    auto neighbours = t.getNeighbours();
    for (auto d : neighbours){
        Entity* targetEntity = d.second->getEntity();
        if(Player* playerPtr = dynamic_cast<Player*>(targetEntity)){
            return attack(d.first, t);
        }
    }
    vector<Direction> directions = getGameDirections();
    
    int num{ rand() % 8 };
    Direction d = directions[num];
    return Enemy::move(d, t);
}

pair<bool, string> Enemy::attack(Direction d, Tile& tile) {
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    Entity* targetEntity = target->getEntity();
    int successfulAttack = rand() % 2;

    // if the target is the player then reduce player hp by current attack
    // kill the enemy if its health falls below 0
    // TODO: Merchant magic
    if (Player* playerPtr = dynamic_cast<Player*>(targetEntity)){
        if(successfulAttack == 1){
             playerPtr->subtractFromHp(ceil((100.0/(100.0+playerPtr->getDefense()))*getAttack()));
            if(playerPtr->getHp() <= 0){
                playerPtr->die();
            }
            return make_pair(true, "Attacked by monster :( \n");
        }else{
            return  make_pair(false, "Haha Monster Missed! \n");
        }
    }else{
        return make_pair(false, "Nothing to attack! \n");
    }
}

pair<bool, string> Enemy::move(Direction d, Tile& tile) {
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    if(target->isMonsterPassable()){
        //cout << "target is passable" << endl;
        //the only passable tiles are those that are empty
        Entity* targetEntity = target->getEntity();

        // check if empty
        if (targetEntity == nullptr){
            //cout << "entity is null" << endl;
        }
        moveNoChecks(d, tile);
        return make_pair(true, "Enemy successfully moved \n");
    }
    else{
        return make_pair(false, "Enemy tried to move but failed \n");
    }
}