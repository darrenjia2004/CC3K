#include "characters/potionfx.h"

Potionfx::Potionfx(int atk, int def): atk{atk}, def{def}, next{std::unique_ptr<Potionfx>{nullptr}} {}

int Potionfx::getAtkChange(){
    return next.get() ? atk + next->getAtkChange() : atk;
}

int Potionfx::getDefChange(){
    return next.get() ? def + next->getDefChange() : def;
}

Potionfx::~Potionfx(){
}
