#ifndef _TILE_H_
#define _TILE_H_
#include <map>
#include <string>
#include <vector>

#include "command.h"
#include "entity.h"
#include "drawable.h"

class Tile : public Drawable {
    int chamberNum;
    std::map<Direction, Tile*> neighbours;
    Entity* entity;

   public:
    const char c;

    Tile(char c);
    virtual char getChar() override;
    int getChamberNum();
    void setChamberNum(int n);
    bool isPassable();
    const std::map<Direction, Tile*>& getNeighbours();
    void setNeighbour(Direction d, Tile* t);
    void notify();
};

#endif