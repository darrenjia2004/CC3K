#include "characters/enemies/werewolf.h"

const char Werewolf::c = 'W';

Werewolf::Werewolf(bool hasCompass) : Enemy{ 'W', 120, 30, 5, hasCompass, 1 , "Werewolf"} {}
