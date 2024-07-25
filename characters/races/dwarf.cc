#include "dwarf.h"

Dwarf::Dwarf() : Player{'@', 100, 20, 30, "Dwarf"} {}

void Dwarf::increaseGold(float gold){
   increaseGold(gold*2.0);
}
