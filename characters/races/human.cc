#include "characters/races/human.h"

Human::Human() : Player{ '@', 140, 20, 20, 140 } {}

string Human::getRace() {
    return "Human";
}

float Human::calculateScore() {
    return getGold() * 1.5;
}
