#include "command.h"
#include "entity.h"
#include "tile.h"

Tile::Tile(char c) : chamberNum{ -1 }, entity{ std::unique_ptr<Entity>{nullptr} }, stairs{ false }, c{ c } {
}

Tile::Tile(Tile&& t) : chamberNum{ t.chamberNum }, entity{ move(t.entity) }, stairs{ t.stairs },
c{ t.c }, neighbours{ t.neighbours } {}

Tile::~Tile() {
}

char Tile::getChar() {
    return entity ? entity->getChar() : (stairs && visibleStairs) ? '\\' : c;
}

int Tile::getChamberNum() {
    return chamberNum;
}

void Tile::setChamberNum(int n) {
    chamberNum = n;
}

bool Tile::isPassable() {
    bool tilePassable = false;
    if (c == '#' || c == '\\' || c == '.' || c == '+') {
        tilePassable = true;
    }

    return entity.get() ? tilePassable && entity->isPassable() : tilePassable;
}

bool Tile::isMonsterPassable() {
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

string Tile::notify() {
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

Entity* Tile::getEntity() {
    return entity.get();
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
