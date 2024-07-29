#include "characters/enemies/goblin.h"

const char Goblin::c = 'N';

Goblin::Goblin(bool hasCompass) : Enemy{ 'N', 70, 5, 10, hasCompass, 1 ,"Goblin"} {}
