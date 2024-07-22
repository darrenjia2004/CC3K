#include "characters/enemies/phoenix.h"

const char Phoenix::c = 'X';

Phoenix::Phoenix(bool hasCompass) : Enemy{50, 35, 20, hasCompass, 1} {}

char Phoenix::getChar() {
    return c;
}
