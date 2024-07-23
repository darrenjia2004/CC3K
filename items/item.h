#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>
#include <vector>
#include "characters/player.h"
using namespace std;

class Item : public Entity{
    bool isUnlocked;
    virtual void applyItemEffect(Player& p) =0;
    public:
    void unlock();
    Item(char c, bool isUnlocked = true);
    virtual ~Item();
};

#endif
