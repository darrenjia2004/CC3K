#include "command.h"
#include "entity.h"
#include "tile.h"

Tile::Tile(char c) : chamberNum{ -1 }, c{ c } {
}

char Tile::getChar() {
    return entity ? entity->getChar() : c;
}

int Tile::getChamberNum() {
    return chamberNum;
}

void Tile::setChamberNum(int n) {
    chamberNum = n;
}

bool Tile::isPassable() {
    if (c == '#' || c == '\\' || c == '.') {
        return true;
    }
    return false;
}

void Tile::setNeighbour(Direction d, Tile* t) {
    neighbours[d] = t;
}

const map<Direction, Tile*>& Tile::getNeighbours() {
    return neighbours;
}

void Tile::notify() {
    char corpse = entity->getChar();
    // check dragon hoard
}

Entity* Tile::getEntity(){
    return entity;
}