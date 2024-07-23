#include "orc.h"

string Orc::getRace(){
    return "Orc";
}

Orc::Orc() : Player{'@', 180, 30, 25, 180} {}

float Orc::calculateScore(){
   return getGold() * 0.5; 
}



