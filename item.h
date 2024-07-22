#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>
#include <vector>
using namespace std;

class Item {
    // Enemy* boss;
    // virtual void applyItemEffect(Player& p) =0;
    public:
    Item();
    virtual ~Item();
};

#endif