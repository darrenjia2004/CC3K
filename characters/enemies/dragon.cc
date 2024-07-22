#include "characters/enemies/dragon.h"

const char Dragon::c = 'D';

Dragon::Dragon(bool hasCompass) : Enemy{150, 20, 20, hasCompass, 0} {}

char Dragon::getChar() {
    return c;
}
