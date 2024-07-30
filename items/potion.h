#ifndef _POTION_H_
#define _POTION_H_
#include <unordered_map>
#include "usableItem.h"
using namespace std;

class Potion : public UsableItem {
    static unordered_map<char, bool> potionVisibility;
    virtual void applyItemEffect(Player& p) override;
    public:
    virtual char getChar() const override;
    const int hp, atk, def;
    Potion(int hp, int atk, int def, char c, string properName);
    static void resetVisibility();
    virtual ~Potion();
};

#endif
