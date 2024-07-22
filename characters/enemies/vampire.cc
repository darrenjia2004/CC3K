#include "characters/enemies/vampire.h"

const char Vampire::c = 'V';

Vampire::Vampire(bool hasCompass) : Enemy{50, 25, 25, hasCompass, 1} {}

char Vampire::getChar() {
    return c;
}
