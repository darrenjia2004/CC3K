#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "drawable.h"
#include "tile.h"
using namespace std;

class Entity : public Drawable {
    vector<Tile*> observers;
    virtual void onDeath();
public:
    Entity(char c);
    const char c;
    virtual char getChar() override;
    virtual void endOfTurnEffect(Tile*);
    virtual bool isPassable();
    bool isMonsterPassable();
    void die();
    virtual void attach(Tile*);
    virtual void detach(Tile*);
    virtual void notifyObservers();

    virtual ~Entity() = 0;
};

#endif
