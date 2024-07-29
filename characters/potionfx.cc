#include "characters/potionfx.h"

Potionfx::Potionfx(int atk, int def): atk{atk}, def{def}, next{std::unique_ptr<Potionfx>{nullptr}} {}

int Potionfx::getAtkChange() const{
    return next.get() ? atk + next->getAtkChange() : atk;
}

int Potionfx::getDefChange() const{
    return next.get() ? def + next->getDefChange() : def;
}

void Potionfx::setNext(Potionfx* p){
    next = std::unique_ptr<Potionfx>(p);
}
