#include "characters/enemies/dragon.h"

const char Dragon::c = 'D';

Dragon::Dragon(bool hasCompass, Tile* ownedItemTile) : Enemy{ 'D', 150, 20, 20, hasCompass, 0 , ownedItemTile} {}

// dragon does not move, so this does nothing
pair<bool, string> Dragon::move(Direction d, Tile& t) {
    return make_pair(false, "Dragons don't move");
}

pair<bool, string> Dragon::attack(Direction d, Tile& t){
    // we have to check if our item and the tile we want to attack are neighbours

    Tile* target = t.getNeighbours().at(d);



    for(auto& candidate: getOwnedItemTile()->getNeighbours()){
        if(candidate.second == target){
            return Character::attack(d, t);
        }
    }

    return make_pair(false, "Not adjacent to owned item");

}