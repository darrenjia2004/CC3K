#ifndef _STEPPABLEITEM_H_
#define _STEPPABLEITEM_H_
#include <string>
#include <vector>
#include "item.h"
using namespace std;

class SteppableItem : public Item {
    public:
    void onStepped(Player& p);
    virtual bool isPassable() const override;
    SteppableItem(char c, string properName, bool isUnlocked = true);
    virtual ~SteppableItem();
};

#endif
