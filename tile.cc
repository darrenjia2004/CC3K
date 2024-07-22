#include "tile.h"

#include "command.h"

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

void Tile::setNeighbour(Direction d, Tile* t) {
    neighbours[d] = t;
}

const map<Direction, Tile*>& Tile::getNeighbours() {
    return neighbours;
}