#include "characters/enemy.h"
#include "items/item.h"
#include <cmath>     // ceil
#include <stdlib.h>  // srand/rand
#include "command.h"

Enemy::Enemy(char c, int maxHp, int atk, int def, bool hasCompass, int goldDrop, Item* ownedItem) 
: Character{ c, maxHp, atk, def, enemyTeam }, hasCompass{ hasCompass }, goldDrop{ goldDrop }, ownedItem{ownedItem} {}

void Enemy::onDeath() {
    if (ownedItem){
        ownedItem->unlock();
    }
}

pair<bool,string> Enemy::endOfTurnEffect(Tile& t) {
    auto neighbours = t.getNeighbours();
    for (auto d : neighbours){
        //we try to attack every entity neighbouring us
        //attack checks if the neighbouring entity is a Character for us
        Entity* targetEntity = d.second->getEntity();
        pair<bool, string> ret{attack(d.first, t)};

        if(ret.first){
            return ret;
        }
    }
    vector<Direction> directions = getGameDirections();
    
    int num{ rand() % 8 };
    Direction d = directions[num];
    return move(d, t);
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

bool Enemy::attackHits(){
    return (rand() % 2) == 1;
}