#include "tile.h"

#include "command.h"

int Tile::chamberCount = 0;

Tile::Tile(char c) : chamberNum{-1}, c{c} {
}

char Tile::getChar() {
    return c;
}

int Tile::getChamberNum() {
    return chamberNum;
}

void Tile::setChamberNum(int n) {
    chamberNum = n;
}

int Tile::incrementChamberCount() {
    return chamberCount++;  // we want the old value
}

void Tile::setNeighbour(Direction d, Tile* t) {
    neighbours[d] = t;
}

const map<Direction, Tile*>& Tile::getNeighbours() {
    return neighbours;
}