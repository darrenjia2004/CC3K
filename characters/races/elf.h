#ifndef _ELF_H_
#define _ELF_H_
#include "characters/player.h"

class Elf : public Player {
public:
    string getRace() override;
    void applyPotion(Potionfx* p) override;
    Elf();
};
#endif
