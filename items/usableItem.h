#ifndef _USABLEITEM_H_
#define _USABLEITEM_H_
#include <string>
#include <vector>
#include "item.h"
using namespace std;
#include "characters/player.h"

class UsableItem : public Item {
    public:
    UsableItem(char c, string properName);
    void onUse(Player& p);
    virtual ~UsableItem();
};

#endif
