#include "characters/enemy.h"

Enemy::Enemy(char c, int maxHp, int atk, int def, bool hasCompass, int goldDrop) : Character{ c, maxHp, atk, def }, hasCompass{ hasCompass }, goldDrop{ goldDrop } {}

// TODO fill these in
void Enemy::onDeath() {}

void Enemy::endOfTurnEffect(Tile& t) {}
