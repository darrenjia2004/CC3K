#ifndef _BARRIERSUIT_H_
#define _BARRIERSUIT_H_
#include "steppableItem.h"
using namespace std;

class BarrierSuit : public SteppableItem {
    virtual void applyItemEffect(Player& p) override;
    public:
    BarrierSuit();
    virtual ~BarrierSuit();
};

#endif
