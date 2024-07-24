#ifndef _USABLEITEM_H_
#define _USABLEITEM_H_
#include <string>
#include <vector>
#include "item.h"
using namespace std;
#include "characters/player.h"

class UsableItem : public Item {
    public:
    UsableItem(char c);
    virtual void onUse(Player& p) = 0;
    virtual ~UsableItem();
};

#endif
