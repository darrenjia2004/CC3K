#include "characters/enemies/goblin.h"

const char Goblin::c = 'N';

Goblin::Goblin(bool hasCompass) : Enemy{70, 5, 10, hasCompass, 1} {}

char Goblin::getChar() {
    return c;
}
