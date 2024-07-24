#include "characters/enemies/dragon.h"

const char Dragon::c = 'D';

Dragon::Dragon(bool hasCompass, Item* ownedItem) : Enemy{ 'D', 150, 20, 20, hasCompass, 0 , ownedItem} {}

void Dragon::onDeath() {}

// dragon does not move, so this does nothing
pair<bool, string> Dragon::move(Direction d, Tile& t) {}
