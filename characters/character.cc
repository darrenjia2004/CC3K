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

// Moves the character without performing any checks
// Precondition: The tile you are trying to move to must be empty or else memory leak
void Character::moveNoChecks(Direction d, Tile& tile){
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    target->setEntity(this);
    tile.setEntity(nullptr);
    this->detach(&tile);
    this->attach(target);
}