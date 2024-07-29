#include "characters/enemies/phoenix.h"

const char Phoenix::c = 'X';
Phoenix::Phoenix(bool hasCompass) : Enemy{ 'X', 50, 35, 20, hasCompass, 1 , "Phoenix"} {}
