#include "orc.h"

string Orc::getRace(){
    return "Orc";
}

Orc::Orc() : Player{'@', 180, 30, 25, 180} {}

void Orc::increaseGold(float gold){
   gold = gold * 0.5; 
}



