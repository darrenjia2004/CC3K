#include "characters/enemy.h"

Enemy::Enemy(bool hasCompass, int goldDrop) : hasCompass{hasCompass}, goldDrop{goldDrop} {}

// TODO fill these in
void Enemy::onDeath() {}

void Enemy::endOfTurnEffect(Tile& t) {}