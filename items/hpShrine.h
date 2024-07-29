#ifndef _HPSHRINE_H_
#define _HPSHRINE_H_
#include "usableItem.h"
using namespace std;

class HpShrine : public UsableItem {
    virtual void applyItemEffect(Player& p) override;
    public:
    HpShrine();
    void onUse(Player& p) override;
    virtual ~HpShrine();
};
#endif
