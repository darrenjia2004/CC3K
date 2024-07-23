#include "human.h"

string Human::getRace(){
    return "Human";
}

Human::Human() : Player{'@', 140, 20, 20, 140} {}

float Human::calculateScore(){
   return getGold() * 1.5; 
}



