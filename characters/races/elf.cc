#include "elf.h"

Elf::Elf() : Player{'@', 140, 30, 10, "Elf"}{}

void Elf::applyPotion(int potionHp, int potionAtk, int potionDef) {
    // for an elf we just use the absolute values of the effects so they're always positive
    Player::applyPotion(abs(potionHp), abs(potionAtk), abs(potionDef));
}
