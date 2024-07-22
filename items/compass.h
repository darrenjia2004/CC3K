#ifndef _COMPASS_H_
#define _COMPASS_H_
#include "steppableItem.h"
using namespace std;

class Compass : public SteppableItem {
    // virtual void applyItemEffect(Player& p) override;
    public:
    Compass();
    virtual ~Compass();
};

#endif