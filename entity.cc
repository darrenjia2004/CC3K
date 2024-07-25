#include "entity.h"
#include <algorithm>

    Entity::Entity(char c): c{c}{}

   char Entity::getChar(){
        return c;
    }

    pair<bool,string> Entity::endOfTurnEffect(Tile& t){
        return make_pair(false, "empty end of turn effect");
    }

    void Entity::setHasDoneEndOfTurn(bool b){
        hasDoneEndOfTurn = b;
    }

    bool Entity::getHasDoneEndOfTurn(){
        return hasDoneEndOfTurn;
    }

    bool Entity::isPassable(){
        return false;
    }

    void Entity::onDeath(){}

    void Entity::die(){
        onDeath();
        notifyObservers();
    }

    void Entity::attach(Tile* t){
        observers.emplace_back(t);
    }

    void Entity::detach(Tile* t){
        observers.erase(remove(observers.begin(), observers.end(), t), observers.end());
    }

    void Entity::notifyObservers(){
        for(auto p: observers) p->notify();
    }

    Entity::~Entity(){}
    