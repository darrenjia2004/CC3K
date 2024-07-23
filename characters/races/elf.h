#ifndef _ELF_H_
#define _ELF_H_
#include "characters/player.h"
#include "items/potion.h"

class Elf : public Player {
public:
    string getRace() override;
    void applyPotion(Potion* p) override;
    Elf();
};
#endif
