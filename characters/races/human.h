#ifndef _HUMAN_H_
#define _HUMAN_H_
#include "characters/player.h"

class Human : public Player {
public:
    Human();
    float calculateScore() const override;
};
#endif
