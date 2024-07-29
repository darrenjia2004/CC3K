#include "entity.h"
#include <algorithm>

Entity::Entity(char c, string properName) : hasDoneEndOfTurn{ false }, c{ c }, properName{ properName } {}

string Entity::getProperName() const {
    return properName;
}
char Entity::getChar() const {
    return c;
}

pair<bool, string> Entity::endOfTurnEffect(Tile& t) {
    return make_pair(false, "empty end of turn effect");
}

void Entity::setHasDoneEndOfTurn(bool b) {
    hasDoneEndOfTurn = b;
}

bool Entity::getHasDoneEndOfTurn() const {
    return hasDoneEndOfTurn;
}

bool Entity::isPassable() const {
    return false;
}

void Entity::onDeath() {}

string Entity::die() {
    onDeath();
    return notifyObservers();
}

void Entity::attach(Tile* t) {
    observers.emplace_back(t);
}

void Entity::detach(Tile* t) {

    auto it = find(observers.begin(), observers.end(), t);

    if (it != observers.end()) {
        observers.erase(it);
    }
}

string Entity::notifyObservers() {
    string ret;
    for (auto p : observers) {
        ret += p->notify() + '\n';
    };

    return ret;
}

Entity* Entity::getLoot() const {
    return nullptr;
}

Entity::~Entity() {}
