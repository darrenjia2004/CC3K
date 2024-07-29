#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>
#include <vector>
#include "characters/player.h"
using namespace std;

class Item : public Entity{
    bool isUnlocked;
    protected:
    virtual void applyItemEffect(Player& p) =0;
    public:
    bool getUnlocked();
    void unlock();
    Item(char c,  string properName, bool isUnlocked = true);
    virtual ~Item();
};

#endif
