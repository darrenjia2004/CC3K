#include "characters/enemies/merchant.h"

const char Merchant::c = 'M';

Merchant::Merchant(bool hasCompass) : Enemy{30, 70, 5, hasCompass, 0} {}

char Merchant::getChar() {
    return c;
}
