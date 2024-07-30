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
    bool hasDoneEndOfTurn;
    const string properName;
public:
    bool getHasDoneEndOfTurn() const;
    void setHasDoneEndOfTurn(bool b);
    Entity(char c, string properName);
    const char c;
    virtual char getChar() const override;
    virtual string getProperName() const;
    virtual pair<bool, string> endOfTurnEffect(Tile& t);
    virtual bool isPassable() const;
    string die();
    virtual void attach(Tile*);
    virtual void detach(Tile*);
    virtual Entity* getLoot() const;
    virtual string notifyObservers();

    virtual ~Entity() = 0;
};

#endif
