#include "characters/races/human.h"

Human::Human() : Player{ '@', 140, 20, 20, "Human"} {}

float Human::calculateScore() {
    return getGold() * 1.5;
}



