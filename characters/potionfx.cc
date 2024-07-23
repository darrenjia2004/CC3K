#include "potionfx.h"

Potionfx::Potionfx(int atk, int def): atk{atk}, def{def} {}

int Potionfx::getAtkChange(){
    return next ? atk + next->getAtkChange() : atk;
}

int Potionfx::getDefChange(){
    return next ? def + next->getDefChange() : def;
}

Potionfx::~Potionfx(){
    delete next;
}