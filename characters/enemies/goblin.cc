#include "characters/enemies/goblin.h"
#include "characters/player.h"

const char Goblin::c = 'N';

Goblin::Goblin(bool hasCompass) : Enemy{ 'N', 70, 5, 10, hasCompass, 1 ,"Goblin"} {}

void Goblin::afterAttacked(Character& attacker){
    Enemy::afterAttacked(attacker);
    Player& playerPtr = dynamic_cast<Player&>(attacker);

    if(playerPtr.hasCompass()){
        playerPtr.loseCompass();
    }
}
