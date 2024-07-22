#include "characters/enemies/dragon.h"

const char Dragon::c = 'D';

Dragon::Dragon(bool hasCompass) : Enemy{ 'D', 150, 20, 20, hasCompass, 0 } {}
