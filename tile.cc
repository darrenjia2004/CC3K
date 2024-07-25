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
    //cout << "tile notified of death" << endl;
    Entity* e = getEntity();
    if(e){
        //cout << "deleting entity" << endl;
        delete e;
    }
    setEntity(nullptr);
}

Entity* Tile::getEntity() {
    return entity;
}

//TODO handle observer attaches/detaches here
void Tile::setEntity(Entity* e) {
    entity = e;
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