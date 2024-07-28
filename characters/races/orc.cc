#include "orc.h"

Orc::Orc() : Player{'@', 180, 30, 25, "Orc"} {}

void Orc::increaseGold(float gold){
    Player::increaseGold(gold*0.5);
}



