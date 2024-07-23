#ifndef _GOLD_H_
#define _GOLD_H_
#include "steppableItem.h"
using namespace std;

class Gold : public SteppableItem {
    virtual void applyItemEffect(Player& p) override;
    public:
    const int goldValue;
    Gold(char c, int goldValue);
    virtual ~Gold();
};

#endif
