#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "tile.h"
using namespace std;

class Entity {
    vector<Tile*> observers;
    virtual void onDeath();
   public: 
    const char c;
    virtual char getChar();
    virtual void endOfTurnEffect(Tile*);
    virtual bool isPassable();
    void die();
    virtual void attach(Tile*);
    virtual void detach(Tile*);
    virtual void notifyObservers();

    virtual ~Entity() = 0;
};

#endif