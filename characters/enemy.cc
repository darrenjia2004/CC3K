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
pair<bool, string> Enemy::move(Direction d, Tile& tile) {}
