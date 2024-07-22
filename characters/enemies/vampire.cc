#include "characters/enemies/vampire.h"

const char Vampire::c = 'V';
Vampire::Vampire(bool hasCompass) : Enemy{ 'V', 50, 25, 25, hasCompass, 1 } {}
