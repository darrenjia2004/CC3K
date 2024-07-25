#include "elf.h"

Elf::Elf() : Player{'@', 140, 30, 10, "Elf"}{}

void Elf::applyPotion(Potionfx* p){
    // for an elf we just make a new pfx object with positive values and delete the old one
    Potionfx* newfx = new Potionfx{p->atk < 0 ? -p->atk : p->atk, p->def < 0 ? -p->def : p->def};
    delete p;
    newfx->next = pfx;
    pfx = newfx;
}