#include "dwarf.h"

string Dwarf::getRace(){
    return "Dwarf";
}

Dwarf::Dwarf() : Player{'@', 100, 20, 30} {}

void Dwarf::increaseGold(float gold){
   increaseGold(gold*2.0);
}
