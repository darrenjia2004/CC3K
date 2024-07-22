#include "characters/enemies/werewolf.h"

const char Werewolf::c = 'W';

Werewolf::Werewolf(bool hasCompass) : Enemy{120, 30, 5, hasCompass, 1} {}

char Werewolf::getChar() {
    return c;
}
