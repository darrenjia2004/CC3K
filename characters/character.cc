#include "characters/character.h"

Character::Character(char c, int maxHp, int atk, int def) : Entity{ c }, maxHp{ maxHp }, atk{ atk }, def{ def }, hp{ maxHp } {}

int Character::getHp() {
    return hp;
}

void Character::addToHp(int n) {
    hp += n;
}

void Character::subtractFromHp(int n) {
    hp -= n;
}