#ifndef _STEPPABLEITEM_H_
#define _STEPPABLEITEM_H_
#include <string>
#include <vector>
#include "item.h"
#include "player.h"
using namespace std;

class SteppableItem : public Item {
    public:
    void onStepped(Player& p);
    virtual bool isPassable() override;
    SteppableItem(char c, bool isUnlocked = true);
    virtual ~SteppableItem();
};

#endif
