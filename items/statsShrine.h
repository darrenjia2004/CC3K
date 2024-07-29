#ifndef _STATSSHRINE_H_
#define _STATSSHRINE_H_
#include "usableItem.h"
using namespace std;

class StatsShrine : public UsableItem {
    virtual void applyItemEffect(Player& p) override;
    public:
    StatsShrine();
    void onUse(Player& p) override;
    virtual ~StatsShrine();
};
#endif
