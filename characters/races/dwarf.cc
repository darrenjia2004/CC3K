#include "dwarf.h"

string Dwarf::getRace(){
    return "Dwarf";
}

Dwarf::Dwarf() : Player{'@', 100, 20, 30, 100} {}

void Dwarf::increaseGold(float gold){
   gold = gold * 2.0; 
}
