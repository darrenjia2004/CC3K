#include "enemy.h"
#include "items/item.h"
#include <cmath>     // ceil
#include <stdlib.h>  // srand/rand
#include "command.h"
#include "items/compass.h"

Enemy::Enemy(char c, int maxHp, int atk, int def, bool compass, int goldDrop, string properName, Tile* ownedItemTile) 
: Character{ c, maxHp, atk, def, enemyTeam, properName }, compass{ compass }, goldDrop{ goldDrop }, ownedItemTile{ownedItemTile} {}

string Enemy::onDeath() {
    if (ownedItemTile && ownedItemTile->getEntity()){
        // invariant: always points to an item
        dynamic_cast<Item*>(ownedItemTile->getEntity())->unlock();

        return ownedItemTile->getEntity()->getProperName() + " is now accessible after death of " + getProperName(); 
    }

    return "";
}

bool Enemy::isHostile() const {
    return true;
}

void Enemy::gainCompass(){
    compass = true;
}

bool Enemy::hasCompass() const{
    return compass;
}

pair<bool,string> Enemy::endOfTurnEffect(Tile& t) {
    auto neighbours = t.getNeighbours();
    if (isHostile()){
        for (auto d : neighbours){
            Entity* targetEntity = d.second->getEntity();
            if(Character* charPtr = dynamic_cast<Character*>(targetEntity)){
                if ((team != charPtr->team)) {
                    return attack(d.first, t);
                }   
            }
        }
    }
    
    vector<Direction> directions = getGameDirections();
    
    int num{ rand() % 8 };
    Direction d = directions[num];
    return move(d, t);
}

// we dont want to print out enemy movement so it is always considered failure.
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
        return make_pair(false, "Enemy successfully moved \n");
    }
    else{
        return make_pair(false, "Enemy tried to move but failed \n");
    }
}

bool Enemy::attackHits() const {
    return (rand() % 2) == 1;
}

void Enemy::afterAttacked(Character& attacker){
    //precondition: attacker is player

    if(getHp() <= 0){
        Player& p = dynamic_cast<Player&>(attacker);
        p.increaseGold(goldDrop);
    }
}

Entity* Enemy::getLoot() const {
    if(compass){
        return new Compass;
    }else{
        return nullptr;
    }
}
Tile* Enemy::getOwnedItemTile() const {
    return ownedItemTile;
}
