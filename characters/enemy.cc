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
    if(target->isPassable()){
        //cout << "target is passable" << endl;
        //the only passable tiles are those that are empty or have a steppable item on them. Technically if the entity exists we know its a steppable item but we check anyways
        Entity* targetEntity = target->getEntity();

        // check if empty or if its a steppable item
        if (targetEntity == nullptr){
            //cout << "entity is null" << endl;
        }
        moveNoChecks(d, tile);
        return make_pair(true, "Player successfully moved \n");
    }
    else{
        return make_pair(false, "Player tried to move but failed \n");
    }
}

