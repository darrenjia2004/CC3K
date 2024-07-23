#include "elf.h"

string Elf::getRace(){
    return "Elf";
}

Elf::Elf() : Player{'@', 140, 30, 10, 140}{}

void Elf::applyPotion(Potion* p){
    int modAtk = p->atk;
    int modDef = p->def;
    if(p->atk < 0){
        modAtk = -p->atk;
    }
    if(p->def < 0){
        modDef = -p->def;
    }
    Potionfx* newPfx = new Potionfx{modAtk, modDef};
    newPfx->next = pfx->next;
    pfx->next = newPfx;
}