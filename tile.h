#ifndef _TILE_H_
#define _TILE_H_
#include <map>
#include <string>
#include <vector>

#include "command.h"
#include "drawable.h"

class Entity;

class Tile : public Drawable {
    int chamberNum;
    std::map<Direction, Tile*> neighbours;
    Entity* entity;
    bool stairs;

public:
    Tile(char c);
    ~Tile();
    const char c;
    Entity* getEntity();
    void setEntity(Entity* e);
    virtual char getChar() override;
    int getChamberNum();
    void setChamberNum(int n);
    bool isPassable();
    bool isMonsterPassable();
    const std::map<Direction, Tile*>& getNeighbours() const;
    void setNeighbour(Direction d, Tile* t);
    void notify();
    void makeStairs();
    bool isStairs();
    void unmakeStairs();
};

#endif
