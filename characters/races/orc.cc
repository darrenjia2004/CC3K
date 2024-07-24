#include "orc.h"

string Orc::getRace(){
    return "Orc";
}

Orc::Orc() : Player{'@', 180, 30, 25} {}

void Orc::increaseGold(float gold){
    increaseGold(gold*0.5);
}



