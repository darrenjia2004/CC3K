#ifndef _DWARF_H_
#define _DWARF_H_
#include "characters/player.h"

class Dwarf : public Player {
public:
    string getRace() override;
    void increaseGold(float gold) override;
    Dwarf();
};
#endif
