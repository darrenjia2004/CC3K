#include "characters/enemies/troll.h"

const char Troll::c = 'T';

Troll::Troll(bool hasCompass) : Enemy{120, 25, 15, hasCompass, 1} {}

char Troll::getChar() {
    return c;
}
