#include "command.h"
#include "entity.h"
#include "tile.h"

Tile::Tile(char c) : chamberNum{ -1 }, entity{ nullptr }, stairs{ false }, c{ c } {
}

Tile::~Tile() {
    delete entity;
}

char Tile::getChar() {
    return entity ? entity->getChar() : stairs ? '\\' : c;
}

int Tile::getChamberNum() {
    return chamberNum;
}

void Tile::setChamberNum(int n) {
    chamberNum = n;
}

bool Tile::isPassable() {
    bool tilePassable = false;
    if (c == '#' || c == '\\' || c == '.' || c == '+') {
        tilePassable = true;
    }
    
    return entity ? tilePassable && entity->isPassable() : tilePassable;
}

bool Tile::isMonsterPassable() {
    bool tilePassable = false;
    if (c == '\\' || c == '.') {
        tilePassable = true;
    }
    return entity ? false : tilePassable;
}

void Tile::setNeighbour(Direction d, Tile* t) {
    neighbours[d] = t;
}

const map<Direction, Tile*>& Tile::getNeighbours() const {
    return neighbours;
}

void Tile::notify() {
    if(entity){
        setEntity(entity->getLoot());
    } 

    //otherwise, entity is nullptr and we don't have to do anything
}

Entity* Tile::getEntity() {
    return entity;
}

void Tile::setEntity(Entity* e, bool deleteOld) {
    if(entity){
        entity->detach(this);

        if(deleteOld){
            delete entity;
        }
    }

    entity = e;

    if(entity){
        entity->attach(this);
    }
}

void Tile::makeStairs() {
    stairs = true;
}

bool Tile::isStairs() {
    return stairs;
}

void Tile::unmakeStairs(){
    stairs = false;
}
