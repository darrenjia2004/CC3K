#ifndef _POTION_H_
#define _POTION_H_
#include "usableItem.h"
using namespace std;

class Potion : public UsableItem {
    // virtual void applyItemEffect(Player& p) override;
    public:
    // char virtual getChar() override;
    const int hp, atk, def;
    Potion(int hp, int atk, int def);
    virtual ~Potion();
};

#endif