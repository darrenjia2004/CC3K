#include <cmath>     // ceil
#include "characters/character.h"

Character::Character(char c, int maxHp, int atk, int def, int team) : 
    Entity{ c }, maxHp{ maxHp }, atk{ atk }, def{ def }, hp{ maxHp }, team{ team } {}

int Character::getHp() {
    return hp;
}

void Character::addToHp(int n) {
    hp += n;
    hp = min(hp, maxHp);
}

void Character::subtractFromHp(int n) {
    hp -= n;
}

int Character::getAttack(){
    return atk;
}

int Character::getDefense(){
    return def;
}

bool Character::attackHits(){
    return true;
}

void Character::afterAttacked(Character& attacker){}

// Moves the character without performing any checks
// Precondition: The tile you are trying to move to must be empty or else memory leak
void Character::moveNoChecks(Direction d, Tile& tile){
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    target->setEntity(this);
    tile.setEntity(nullptr, false);
}

pair<bool, string> Character::attack(Direction d, Tile& tile) {
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    Entity* targetEntity = target->getEntity();

    // if the target is not the same team, try to attack
    // kill the enemy if its health falls below 0
    if (Character* charPtr = dynamic_cast<Character*>(targetEntity)) {
        if ((team == charPtr->team)) {
            return make_pair(false, "Did not attack bc same team :( \n");
        }
        if (!attackHits()){
            return make_pair(true, "Attack missed \n");
        }
        else{
            charPtr->subtractFromHp(ceil((100.0 / (100.0 + charPtr->getDefense())) * getAttack()));
            charPtr->afterAttacked(*this);
            if (charPtr->getHp() <= 0) {
                charPtr->die();
            }
            return make_pair(true, "Successfully attacked \n");
        }
    }
    else {
        return make_pair(false, "Nothing to attack! \n");
    }
}