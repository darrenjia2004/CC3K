#include "gameModel.h"
#include "characters/player.h"
#include "characters/races/dwarf.h"
#include "characters/races/elf.h"
#include "characters/races/human.h"
#include "characters/races/orc.h"
#include "items/potion.h"
#include "items/gold.h"
#include "items/barrierSuit.h"
#include "characters/enemies/werewolf.h"
#include "characters/enemies/vampire.h"
#include "characters/enemies/goblin.h"
#include "characters/enemies/troll.h"
#include "characters/enemies/phoenix.h"
#include "characters/enemies/merchant.h"
#include "characters/enemies/dragon.h"

#include <chrono>
#include <stdlib.h>  // srand/rand
#include <unistd.h>  //getpid

unordered_map<char, bool> GameModel::potionVisibility;

GameModel::GameModel(Action a) : playerRaceAction{ a }, chamberCount{ 0 }, randomSeed{ std::chrono::system_clock::now().time_since_epoch().count() },
floor{ 1 }, rawMap{ unique_ptr<Tile * []>{} } {
    srand(randomSeed);
    barrierSuitFloor = rand() % numFloors;
    init();
}

GameModel::~GameModel() {
}

void GameModel::init() {
    setPotionVis();
    loadTiles();
    loadNeighbours();
    loadChambers();
    generatePlayer();
    generate();
}

GameModel::State GameModel::getState() {
    if (!getPlayer()) { //player is killed
        return State::LOST;
    }

    if (floor > numFloors) {
        return State::WON;
    }

    return State::IN_PROGRESS;
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
            map[row].push_back(move(t));
        }
    }
    file.close();

    //then also load in rawMap (precondition: rawMap does not hold any tiles)
    rawMap = unique_ptr<Tile * []>(new Tile * [map.size()]);

    for (int i = 0; i < map.size(); ++i) {
        rawMap[i] = &map[i][0];
    }
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

// if the provided player is null, create a new player and add it to a random tile, otherwise put the provided player on the board
void GameModel::generatePlayer(Player* player) {
    if (player) {
        player->clearPotions();
        pair<int, int> newCoords = addToRandomTile(nullptr, true);
        Tile& newTile = map[newCoords.first][newCoords.second];
        map[playerCoords.first][playerCoords.second].moveEntityTo(newTile);
        playerCoords = newCoords;
    }
    else {
        switch (playerRaceAction) {
        case Action::SELECTDWARF:
            playerCoords = addToRandomTile(new Dwarf(), true);
            break;
        case Action::SELECTELF:
            playerCoords = addToRandomTile(new Elf(), true);
            break;
        case Action::SELECTORC:
            playerCoords = addToRandomTile(new Orc(), true);
            break;
        case Action::SELECTHUMAN:
        default:
            playerCoords = addToRandomTile(new Human(), true);
            break;
        }
    }
}

void GameModel::generate() {
    //stair generation
    pair<int, int> sCoords{ addToRandomTile(nullptr, false) };
    stairCoords = sCoords;
    map[sCoords.first][sCoords.second].makeStairs();

    //potion generation
    for (int i = 0; i < numPotions; ++i) {
        addToRandomTile(getRandomPotion(), true);
    }

    vector<pair<int, int>> dragonHordes;

    //gold generation
    for (int i = 0; i < numGolds; ++i) {
        Gold* g = getRandomGold();
        pair<int, int> p{ addToRandomTile(g, true) };

        if (g->goldValue == 6) { //dragon hoard
            dragonHordes.push_back(p);
        }
    }

    //barrier suit generation
    if (floor == barrierSuitFloor) {
        BarrierSuit* bs = new BarrierSuit{};
        pair<int, int> p{ addToRandomTile(bs, true) };

        dragonHordes.push_back(p);
    }

    //enemy generation
    int compassIndex{ rand() % numEnemies };
    int index{ 0 };

    for (pair<int, int> coord : dragonHordes) {
        //find neighbour of tile
        Tile* neighbour = getRandomNeighbour(map[coord.first][coord.second]);

        Dragon* d = new Dragon(compassIndex == index, &map[coord.first][coord.second]);
        neighbour->setEntity(d);
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
        return new Potion{ 10, 0, 0, '0', "RH" };
    case 1: //BA
        return new Potion{ 0, 5, 0, '1', "BA" };
    case 2: //BD
        return new Potion{ 0, 0, 5, '2', "BD" };
    case 3: //PH
        return new Potion{ -10, 0, 0, '3', "PH" };
    case 4: //WA
        return new Potion{ 0, -5, 0, '4', "WA" };
    default: // corresponds to 5, WD
        return new Potion{ 0, 0, -5, '5', "WD" };
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
        return new Gold{ 1 }; //normal
    case 5:
    case 6:
        return new Gold{ 2 }; //small hoard
    default: // 7
        return new Gold{ 6, false }; //dragon hoard
    }
}

Enemy* GameModel::getRandomEnemy(bool hasCompass) {
    int num{ rand() % 18 };
    if (hasCompass) {
        // we aint gonna let merchant have da compass
        while (num >= 16) {
            num = rand() % 18;
        }
    }
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
    default: //16, 17
        return new Merchant(hasCompass);
    }
}

Tile* GameModel::getRandomNeighbour(const Tile& current) {
    vector<Direction> dirs{ getGameDirections() };
    const std::map<Direction, Tile*> neighbours{ current.getNeighbours() };

    Direction d{ dirs[rand() % dirs.size()] };
    auto iter{ neighbours.find(d) };

    // in our case, the third condition implies the second, but this is more general
    while ((iter == neighbours.end()) || !iter->second->isMonsterPassable() || iter->second->getEntity()) {
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
        map[p.first][p.second].getEntity() || p == stairCoords
        ) {
        p = getRandomTile();
    }

    map[p.first][p.second].setEntity(e);
    return p;
}



bool GameModel::inBounds(const pair<int, int>& pos) {
    return pos.first < map.size() && pos.second < map[pos.first].size();
}

pair<int, int> operator+(const pair<int, int>& p1, const pair<int, int>& p2) {
    return { p1.first + p2.first, p1.second + p2.second };
}


Player* GameModel::getPlayer() {
    Entity* e = getPlayerTile().getEntity();

    if (e) {
        return static_cast<Player*>(e);
    }

    return nullptr;
}

Tile& GameModel::getPlayerTile() {
    return map[playerCoords.first][playerCoords.second];
}

int GameModel::getFloor() {
    return floor;
}

Tile** GameModel::getRawMap() {
    return rawMap.get();
}

void GameModel::resetBoard() {
    // detach the player tile from player so we dont remove it

    // clear all the non player entities
    for (auto& v : map) {
        for (auto& t : v) {
            Entity* e = t.getEntity();
            if (e != getPlayer()) {
                t.setEntity(nullptr);
            }
        }
    }

    map[stairCoords.first][stairCoords.second].unmakeStairs();
    stairCoords = { -1,-1 };
}

string GameModel::playerTurn(Command c) {
    string actionString;
    switch (c.action)
    {
    case Action::MOVE: {
        auto p = getPlayer()->move(c.direction, getPlayerTile());
        if (p.first) {
            playerCoords = playerCoords + getCoords(c.direction);
        }
        actionString = p.second;
        break;
    }
    case Action::USE: {
        actionString = getPlayer()->use(c.direction, getPlayerTile()).second;
        break;
    }
    case Action::ATTACK: {
        actionString = getPlayer()->attack(c.direction, getPlayerTile()).second;
        break;
    }
    default:
        return "Invalid Command \n";
    }
    if (stairCoords == playerCoords) {
        floor++;
        Player* p = getPlayer();
        resetBoard();
        generatePlayer(p);
        generate();
        return "PC moved onto stairs \n";
    }

    //trigger the end of turn effects for all entities
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size();j++) {
            Entity* e = map[i][j].getEntity();
            if (e && !e->getHasDoneEndOfTurn()) {
                auto res = e->endOfTurnEffect(map[i][j]);
                if (res.first) {
                    actionString += res.second;
                }
                e->setHasDoneEndOfTurn(true);
            }
        }
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size();j++) {
            Entity* e = map[i][j].getEntity();
            if (e) {
                e->setHasDoneEndOfTurn(false);
            }
        }
    }


    if (getPlayer() && getPlayer()->hasCompass()) {
        map[stairCoords.first][stairCoords.second].show();
    }

    return actionString;
}
