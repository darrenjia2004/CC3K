#ifndef _ORC_H_
#define _ORC_H_
#include "characters/player.h"

class Orc : public Player {
public:
    string getRace() override;
    void increaseGold(float gold) override;
    Orc();
};
#endif
