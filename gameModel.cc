#include "gameModel.h"
#include "characters/player.h"
#include "characters/races/human.h"
#include "items/potion.h"
#include "items/gold.h"
#include "characters/enemies/werewolf.h"
#include "characters/enemies/vampire.h"
#include "characters/enemies/goblin.h"
#include "characters/enemies/troll.h"
#include "characters/enemies/phoenix.h"
#include "characters/enemies/merchant.h"
#include "characters/enemies/dragon.h"


#include <stdlib.h>  // srand/rand
#include <unistd.h>  //getpid

unordered_map<char, bool> GameModel::potionVisibility;

GameModel::GameModel() : chamberCount{ 0 }, randomSeed{ getpid() } {
    srand(randomSeed);
    init();
}

void GameModel::init() {
    setPotionVis();
    loadTiles();
    loadNeighbours();
    loadChambers();
    generate();
}

// sets the potion visibilities to false
void GameModel::setPotionVis() {
    for (int i = 0; i < 6; i++) {
        potionVisibility['0' + i] = false;
    }
}

// method which loads the default map into the tile map
void GameModel::loadTiles() {
    string line;
    ifstream file("defaultMap.txt");
    int row = -1;
    while (getline(file, line)) {
        map.push_back(vector<Tile>());
        row++;
        for (int i = 0; i < line.length(); i++) {
            Tile t{ line[i] };
            map[row].push_back(t);
        }
    }
    file.close();
}

void GameModel::loadNeighbours() {
    vector<Direction> dirs{ getGameDirections() };

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            for (Direction d : dirs) {
                // for every direction, check if in bounds and add to array
                pair<int, int> neighbourPosition{ pair<int, int>(i, j) + getCoords(d) };

                if (inBounds(neighbourPosition)) {
                    map[i][j].setNeighbour(d, &map[neighbourPosition.first][neighbourPosition.second]);
                }
            }
        }
    }
}

void GameModel::loadChambers() {
    for (vector<Tile>& row : map) {
        for (Tile& t : row) {
            // if we find a tile that needs to be filled but hasn't, then fill it with new chamber number
            if (t.c == '.' && t.getChamberNum() == -1) {
                floodFill(t, chamberCount);
                ++chamberCount;
            }
        }
    }
}

void GameModel::floodFill(Tile& t, int n) {
    auto& neighbours{ t.getNeighbours() };
    t.setChamberNum(n);

    for (auto iter = neighbours.begin(); iter != neighbours.end(); ++iter) {
        Tile* neighbour{ iter->second };

        // if neighbour needs chamber and doesnt have one assigned, then recurse
        if (neighbour->c == '.' && neighbour->getChamberNum() == -1) {
            floodFill(*neighbour, n);
        }
    }
}

void GameModel::generate() {
    //player generation
    Player* p = new Human();
    playerCoords = addToRandomTile(p, true);

    //stair generation
    pair<int, int> stairCoords{ addToRandomTile(nullptr, false) };
    map[stairCoords.first][stairCoords.second].makeStairs();

    //potion generation
    for (int i = 0; i < numPotions; ++i) {
        addToRandomTile(getRandomPotion(), true);
    }

    vector<pair<int, int>> dragonHordes;

    //gold generation
    for (int i = 0; i < numGolds; ++i) {
        Gold* g = getRandomGold();
        pair<int, int> p{ addToRandomTile(g, true) };

        if (g->c == '9') { //dragon hoard
            dragonHordes.push_back(p);
        }
    }

    //enemy generation
    int compassIndex{ rand() % numEnemies };
    int index{ 0 };

    for (pair<int, int> coord : dragonHordes) {
        //find neighbour of tile
        Tile* neighbour = getRandomNeighbour(map[coord.first][coord.second]);

        while (neighbour->getEntity()) {
            neighbour = getRandomNeighbour(map[coord.first][coord.second]);
        }
        neighbour->setEntity(new Dragon(compassIndex == index, static_cast<Item*>(map[coord.first][coord.second].getEntity())));
        ++index;
    }

    for (;index < numEnemies; ++index) {
        addToRandomTile(getRandomEnemy(compassIndex == index), true);
    }

    //TODO checks for at least one free space next to dragon hoard
}

pair<int, int> GameModel::getRandomTile() {
    int randomChamber{ rand() % chamberCount };

    int row{ rand() % map.size() };
    int col{ rand() % map[row].size() };

    while (map[row][col].getChamberNum() != randomChamber) {
        row = rand() % map.size();
        col = rand() % map[row].size();
    }

    return { row, col };
}

Potion* GameModel::getRandomPotion() {
    int num{ rand() % 6 };

    switch (num) {
    case 0: //RH
        return new Potion{ 10, 0, 0, '0' };
    case 1: //BA
        return new Potion{ 0, 5, 0, '1' };
    case 2: //BD
        return new Potion{ 0, 0, 5, '2' };
    case 3: //PH
        return new Potion{ -10, 0, 0, '3' };
    case 4: //WA
        return new Potion{ 0, -5, 0, '4' };
    case 5: //WD
        return new Potion{ 0, 0, -5, '5' };
    }
}

Gold* GameModel::getRandomGold() {
    int num{ rand() % 8 };

    switch (num) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return new Gold{ '6', 1 }; //normal
    case 5:
    case 6:
        return new Gold{ '7', 2 }; //small hoard
    case 7:
        return new Gold{ '9', 6, false}; //dragon hoard
    }
}

Enemy* GameModel::getRandomEnemy(bool hasCompass) {
    int num{ rand() % 18 };
    switch (num) {
    case 0:
    case 1:
    case 2:
    case 3:
        return new Werewolf(hasCompass);
    case 4:
    case 5:
    case 6:
        return new Vampire(hasCompass);
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return new Goblin(hasCompass);
    case 12:
    case 13:
        return new Troll(hasCompass);
    case 14:
    case 15:
        return new Phoenix(hasCompass);
    case 16:
    case 17:
        return new Merchant(hasCompass);
    }
}

Tile* GameModel::getRandomNeighbour(const Tile& current) {
    vector<Direction> dirs{ getGameDirections() };
    const std::map<Direction, Tile*> neighbours{ current.getNeighbours() };

    Direction d{ dirs[rand() % dirs.size()] };
    auto iter{ neighbours.find(d) };

    while (iter == neighbours.end()) {
        d = dirs[rand() % dirs.size()];
        iter = neighbours.find(d);
    }

    return iter->second;
}

pair<int, int> GameModel::addToRandomTile(Entity* e, bool canBeWithPlayer) {
    //precondition: player has been loaded in if canBeWithPlayer = false

    pair<int, int> p{ getRandomTile() };

    while (
        (!canBeWithPlayer &&
            (map[p.first][p.second].getChamberNum() ==
                map[playerCoords.first][playerCoords.second].getChamberNum())) ||
        map[p.first][p.second].getEntity()
        ) {
        p = getRandomTile();
    }

    map[p.first][p.second].setEntity(e);
    if (e){
        e->attach(&map[p.first][p.second]);
    }
    return p;
}

// utility functions
pair<int, int> GameModel::getCoords(Direction d) {
    switch (d) {
    case Direction::NO:
        return { -1, 0 };
    case Direction::SO:
        return { 1, 0 };
    case Direction::EA:
        return { 0, 1 };
    case Direction::WE:
        return { 0, -1 };
    case Direction::NE:
        return { -1, 1 };
    case Direction::NW:
        return { -1, -1 };
    case Direction::SE:
        return { 1, 1 };
    case Direction::SW:
        return { 1, -1 };
    default:
        return { 0, 0 };
    }
}

bool GameModel::inBounds(const pair<int, int>& pos) {
    return pos.first < map.size() && pos.second < map[pos.first].size();
}

pair<int, int> operator+(const pair<int, int>& p1, const pair<int, int>& p2) {
    return { p1.first + p2.first, p1.second + p2.second };
}

vector<Direction> GameModel::getGameDirections() {
    return {
        Direction::NO,
        Direction::SO,
        Direction::EA,
        Direction::WE,
        Direction::NE,
        Direction::NW,
        Direction::SE,
        Direction::SW,
    };
}

Player* GameModel::getPlayer() {
    return static_cast<Player*>(getPlayerTile().getEntity());
}

Tile& GameModel::getPlayerTile(){
    return map[playerCoords.first][playerCoords.second];
}

int GameModel::getFloor() {
    return floor;
}

string GameModel::playerTurn(Command c) {
    switch (c.action)
    {
        case Action::MOVE:{
            auto p = getPlayer()->move(c.direction, getPlayerTile());
            if (p.first){
                playerCoords = playerCoords + getCoords(c.direction); 
            }
            return p.second;
        }
        case Action::USE:{
            return getPlayer()->use(c.direction, getPlayerTile()).second;
        }
        default:
            return "some other action \n";
    }
}
