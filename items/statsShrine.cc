#include "items/statsShrine.h"

StatsShrine::StatsShrine(): UsableItem{'S', "Stats Shrine"}{
    
}

StatsShrine::~StatsShrine(){
    
}

void StatsShrine::applyItemEffect(Player& p){
    p.activateStatsShrine();
}

void StatsShrine::onUse(Player& p){
    if(p.getHp() > 10){
        applyItemEffect(p);
    }else{
        p.die();
    }
}
