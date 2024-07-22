#ifndef _TILE_H_
#define _TILE_H_
#include <map>
#include <string>
#include <vector>

#include "command.h"
#include "entity.h"

class Tile {
    int chamberNum;
    std::map<Direction, Tile*> neighbours;
    Entity* entity;

   public:
    const char c;

    Tile(char c);
    char getChar();
    int getChamberNum();
    void setChamberNum(int n);
    const std::map<Direction, Tile*>& getNeighbours();
    void setNeighbour(Direction d, Tile* t);
    void notify();
};

#endif