#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "drawable.h"

class Observer;
class Tile;

using namespace std;

class Entity : public Drawable {
    vector<Observer*> observers;
    virtual string onDeath();
    bool hasDoneEndOfTurn;
    const string properName;
    bool alive;
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
    bool isAlive() const;
    virtual void attach(Observer*);
    virtual void detach(Observer*);
    virtual Entity* getLoot() const;
    virtual string notifyObservers();

    virtual ~Entity() = 0;
};

#endif
