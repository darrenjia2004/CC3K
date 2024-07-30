#ifndef _ELF_H_
#define _ELF_H_
#include "characters/player.h"

class Elf : public Player {
public:
    void applyPotion(int potionHp, int potionAtk, int potionDef) override;
    Elf();
};
#endif
