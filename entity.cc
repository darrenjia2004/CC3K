#include "entity.h"
#include <algorithm>

    Entity::Entity(char c): hasDoneEndOfTurn{false}, c{c}, observers{vector<Tile*>()}{}

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

        auto it = find(observers.begin(), observers.end(), t);

        if(it != observers.end()){
            observers.erase(it);
        }
    }

    void Entity::notifyObservers(){
        for(auto p: observers) p->notify();
    }

    Entity::~Entity(){}
    