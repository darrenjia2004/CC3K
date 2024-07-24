#include "characters/enemy.h"
#include "items/item.h"

Enemy::Enemy(char c, int maxHp, int atk, int def, bool hasCompass, int goldDrop, Item* ownedItem) 
: Character{ c, maxHp, atk, def }, hasCompass{ hasCompass }, goldDrop{ goldDrop }, ownedItem{ownedItem} {}

// TODO fill these in
void Enemy::onDeath() {
    if (ownedItem){
        ownedItem->unlock();
    }
}

void Enemy::endOfTurnEffect(Tile& t) {}

void Enemy::attack(Direction d, Tile& tile) {}

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