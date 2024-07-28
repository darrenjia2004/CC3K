#ifndef _ELF_H_
#define _ELF_H_
#include "characters/player.h"

class Elf : public Player {
public:
    void applyPotion(unique_ptr<Potionfx> p) override;
    Elf();
};
#endif
