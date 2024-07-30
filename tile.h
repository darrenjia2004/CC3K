#ifndef _TILE_H_
#define _TILE_H_
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "command.h"
#include "drawable.h"
#include "observer.h"
#include "entity.h"

class Tile : public Drawable, public Observer {
    int chamberNum;
    std::map<Direction, Tile*> neighbours;
    std::unique_ptr<Entity> entity;
    bool stairs;
    bool visibleStairs;

public:
    Tile(char c);
    const char c;
    Entity* getEntity() const;
    Entity* takeEntity();
    void setEntity(Entity* e);
    virtual char getChar() const override;
    int getChamberNum() const;
    void setChamberNum(int n);
    bool isPassable() const;
    bool isMonsterPassable() const;
    void moveEntityTo(Tile& other);
    const std::map<Direction, Tile*>& getNeighbours() const;
    void setNeighbour(Direction d, Tile* t);
    string notify(Entity& e) override;
    void makeStairs();
    void showStairs();
    void hideStairs();
    bool isStairs();
    void unmakeStairs();
};

#endif
