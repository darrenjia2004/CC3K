#ifndef _TILE_H_
#define _TILE_H_
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "command.h"
#include "drawable.h"

class Entity;

class Tile : public Drawable {
    int chamberNum;
    std::map<Direction, Tile*> neighbours;
    std::unique_ptr<Entity> entity;
    bool stairs;
    bool visibleStairs;

public:
    Tile(char c);
    Tile(Tile&& t);
    ~Tile();
    const char c;
    Entity* getEntity();
    void setEntity(Entity* e);
    virtual char getChar() override;
    int getChamberNum();
    void setChamberNum(int n);
    bool isPassable();
    bool isMonsterPassable();
    void moveEntityTo(Tile& other);
    const std::map<Direction, Tile*>& getNeighbours() const;
    void setNeighbour(Direction d, Tile* t);
    string notify();
    void makeStairs();
    void showStairs();
    void hideStairs();
    bool isStairs();
    void unmakeStairs();
};

#endif
