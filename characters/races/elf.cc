#include "elf.h"

Elf::Elf() : Player{'@', 140, 30, 10, "Elf"}{}

void Elf::applyPotion(unique_ptr<Potionfx> p){
    // for an elf we just make a new pfx object with positive values
    unique_ptr<Potionfx> newfx = make_unique<Potionfx>(p->atk < 0 ? -p->atk : p->atk, p->def < 0 ? -p->def : p->def);
    newfx->next = std::move(pfx);
    pfx = std::move(newfx);
}
