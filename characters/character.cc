#include <cmath>     // ceil
#include "characters/character.h"

Character::Character(char c, int maxHp, int atk, int def, int team, string properName) :
    Entity{ c , properName }, maxHp{ maxHp }, atk{ atk }, def{ def }, hp{ maxHp }, team{ team } {}

int Character::getHp() const {
    return hp;
}

int Character::getMaxHp() const {
    return maxHp;
}

void Character::addToHp(int n) {
    hp += n;
    hp = min(hp, maxHp);
}

int Character::subtractFromHp(int n) {
    hp -= n;
    return n;
}

void Character::addToStatsRandom() {
    int addAtk = rand() % 2;
    if(addAtk == 0){
        atk += 20;
    }else{
        def += 20;
    }
}

int Character::getAttack() const {
    return atk;
}

int Character::getDefense() const {
    return def;
}

bool Character::attackHits() const {
    return true;
}

void Character::afterAttacked(Character& attacker) {}

// Moves the character without performing any checks
// Precondition: The tile you are trying to move to must be empty or else memory leak
void Character::moveNoChecks(Direction d, Tile& tile) {
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    target->setEntity(tile.takeEntity());
}

pair<bool, string> Character::attack(Direction d, Tile& tile) {
    auto neighbours = tile.getNeighbours();
    Tile* target = neighbours[d];
    Entity* targetEntity = target->getEntity();
    string name = getProperName();
    // if the target is not the same team, try to attack
    // kill the enemy if its health falls below 0
    // returns true if the attack succesfully went off whether it hit or not
    if (Character* charPtr = dynamic_cast<Character*>(targetEntity)) {
        string enemyName = charPtr->getProperName();
        if (!attackHits()) {
            return make_pair(true, name + "'s attack against " + enemyName + " missed \n");
        }
        else {
            int damage = charPtr->subtractFromHp(ceil((100.0 / (100.0 + charPtr->getDefense())) * getAttack()));
            charPtr->afterAttacked(*this);
            string enemyDiedString = "";
            if (charPtr->getHp() <= 0) {
                enemyDiedString = "and " + enemyName + " died";
                enemyDiedString += '\n' + charPtr->die();
            }
            return make_pair(true,
                name + " attacked " + enemyName + " for " + to_string(damage) + " damage " + enemyDiedString + "\n");
        }
    }
    else {
        return make_pair(false, name + " attacked nothing \n");
    }
}
