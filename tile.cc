#include "command.h"
#include "tile.h"

Tile::Tile(char c) : chamberNum{ -1 }, entity{ std::unique_ptr<Entity>{nullptr} }, stairs{ false }, c{ c } {
}

char Tile::getChar() const {
    return entity ? entity->getChar() : (stairs && visibleStairs) ? '\\' : c;
}

int Tile::getChamberNum() const {
    return chamberNum;
}

void Tile::setChamberNum(int n) {
    chamberNum = n;
}

bool Tile::isPassable() const {
    bool tilePassable = false;
    if (c == '#' || c == '\\' || c == '.' || c == '+') {
        tilePassable = true;
    }

    return entity.get() ? tilePassable && entity->isPassable() : tilePassable;
}

bool Tile::isMonsterPassable() const {
    bool tilePassable = false;
    if (c == '\\' || c == '.') {
        tilePassable = true;
    }
    return entity.get() ? false : tilePassable;
}

void Tile::setNeighbour(Direction d, Tile* t) {
    neighbours[d] = t;
}

const map<Direction, Tile*>& Tile::getNeighbours() const {
    return neighbours;
}

string Tile::notify(Entity& e) {
    if((&e != entity.get())){
        return "";
    }

    string ret{""};

    if (entity.get()) {

        Entity* loot = entity->getLoot();

        if (loot) {
            string entityName{entity->getProperName()};
            string lootName{loot->getProperName()};
            if(entityName == lootName){
                ret = "In the place of " + entityName + ", another " + lootName + " appeared";
            }
            else {
                ret = "In the place of " + entity->getProperName() + ", " + loot->getProperName() + " appeared";
            }
        }

        setEntity(loot);
    }

    //otherwise, entity is nullptr and we don't have to do anything
    return ret;
}

Entity* Tile::getEntity() const {
    return entity.get();
}

Entity* Tile::takeEntity(){
    entity->detach(this);
    return entity.release();
}

void Tile::moveEntityTo(Tile& other) {
    entity->detach(this);
    entity->attach(&other);

    other.entity = move(entity);
    entity = nullptr;

}

void Tile::setEntity(Entity* e) {
    if (entity.get()) {
        entity->detach(this);
    }

    entity = unique_ptr<Entity>(e);

    if (entity.get()) {
        entity->attach(this);
    }
}

void Tile::makeStairs() {
    stairs = true;
    hideStairs();
}

bool Tile::isStairs() {
    return stairs;
}

void Tile::showStairs() {
    visibleStairs = true;
}

void Tile::hideStairs() {
    visibleStairs = false;
}

void Tile::unmakeStairs() {
    stairs = false;
}
