#ifndef _PHOENIX_H_
#define _PHOENIX_H_
#include "characters/enemy.h"

class Phoenix : public Enemy {
    static const int maxRegens = 3;
    const int regenCount;
public:
    static const char c;
    Phoenix(bool hasCompass, int regenCount = 1);
    Entity* getLoot() const override;
};
#endif
