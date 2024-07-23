#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>
#include <vector>
#include "entity.h"
using namespace std;

class Item : public Entity{
    // Enemy* boss;
    // virtual void applyItemEffect(Player& p) =0;
    public:
    Item(char c);
    virtual ~Item();
};

#endif
