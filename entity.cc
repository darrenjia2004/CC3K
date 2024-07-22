#include "entity.h"

   char Entity::getChar(){
        return c;
    }

    void Entity::endOfTurnEffect(Tile*){

    }

    bool Entity::isPassable(){
    }

    void Entity::onDeath(){}

    void Entity::die(){
        onDeath();
        notifyObservers();
    }

    void Entity::attach(Tile* t){
        observers.emplace_back(t);
    }

    void Entity::detach(Tile* t){}

    void Entity::notifyObservers(){
        for(auto p: observers) p->notify();
    }

    Entity::~Entity(){}