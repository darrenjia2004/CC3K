#ifndef _TILE_H_
#define _TILE_H_
#include <map>
#include <string>
#include <vector>

#include "command.h"

class Tile {
    // holds the current number of chambers
    static int chamberCount;

    int chamberNum;
    std::map<Direction, Tile*> neighbours;

   public:
    const char c;

    Tile(char c);
    char getChar();
    int getChamberNum();
    void setChamberNum(int n);
    const std::map<Direction, Tile*>& getNeighbours();
    void setNeighbour(Direction d, Tile* t);
    static int incrementChamberCount();
};

#endif