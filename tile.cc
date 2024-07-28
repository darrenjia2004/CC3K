#include "command.h"
#include "entity.h"
#include "tile.h"

Tile::Tile(char c) : chamberNum{ -1 }, entity{ std::unique_ptr<Entity>{nullptr} }, stairs{ false }, c{ c } {
}

Tile::Tile(Tile&& t): chamberNum{t.chamberNum}, entity{move(t.entity)}, stairs{t.stairs}, 
c{t.c}, neighbours{t.neighbours}{}

Tile::~Tile() {
}

char Tile::getChar() {
    return entity.get() ? entity->getChar() : stairs ? '\\' : c;
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

void Tile::notify() {
    //cout << "tile notified of death" << endl;
    // Entity* e = getEntity();
    // if(e){
        // //cout << "deleting entity" << endl;
        //delete e;
    // }
    setEntity(nullptr);
}

Entity* Tile::getEntity() {
    return entity.get();
}

void Tile::moveEntityTo(Tile& other){
    other.entity = move(entity);
    entity = nullptr;
}

//TODO handle observer attaches/detaches here
void Tile::setEntity(Entity* e) {
    entity = unique_ptr<Entity>(e);
}

void Tile::makeStairs() {
    stairs = true;
}

bool Tile::isStairs() {
    return stairs;
}

void Tile::unmakeStairs(){
    stairs = false;
}
