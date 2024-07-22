#include "potionfx.h"

Potionfx::Potionfx(int atk, int def): atk{atk}, def{def} {}

int Potionfx::getAtkChange(){
    return atk;
}

int Potionfx::getDefChange(){
    return def;
}