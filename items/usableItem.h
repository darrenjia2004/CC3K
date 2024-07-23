#ifndef _USABLEITEM_H_
#define _USABLEITEM_H_
#include <string>
#include <vector>
#include "item.h"
using namespace std;

class UsableItem : public Item {
    public:
    // void onUse(Player& p);
    UsableItem(char c);
    virtual ~UsableItem();
};

#endif
