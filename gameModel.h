#ifndef _GAMEMODEL_H_
#define _GAMEMODEL_H_
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <vector>
#include <unordered_map>
#include "command.h"
#include "tile.h"
#include "command.h"

class Player;
class Potion;
class Gold;
class Enemy;

using namespace std;

class GameModel {
    static const int numFloors{ 5 };
    static const int numPotions{ 10 };
    static const int numGolds{ 10 };
    static const int numEnemies{ 20 };
    const Action playerRaceAction;
    pair<int, int> playerCoords;
    int chamberCount;
    const unsigned randomSeed;
    int barrierSuitFloor;
    int floor;
    pair<int, int> stairCoords;
    unique_ptr<Tile* []> rawMap;
    const string maptxt;

    void generateWithText(Player* p = nullptr);
    void init();
    void loadTiles();
    void loadNeighbours();
    void loadChambers();
    void floodFill(Tile& t, int n);
    void generate();
    pair<int, int> addToRandomTile(Entity* e, bool canBeWithPlayer);

    bool inBounds(const pair<int, int>& pos);
    pair<int, int> getRandomTile() const;
    Potion* getRandomPotion() const;
    Gold* getRandomGold() const;
    Enemy* getRandomEnemy(bool hasCompass) const;
    Tile* getRandomNeighbour(const Tile& current) const;
    void setPotionVis();
    Tile& getPlayerTile();
    const Tile& getPlayerTile() const;
    void generatePlayer(Player* player = nullptr);
    void generatePlayer(pair<int, int> pcoord, Player* player = nullptr);
    Entity* getEntityForChar(char c) const;
    void resetBoard();

public:
    enum class State {
        IN_PROGRESS,
        WON,
        LOST
    };

    static unordered_map<char, bool> potionVisibility;
    vector<vector<Tile>> map;

    string playerTurn(Command c);
    int getFloor() const;
    Player* getPlayer() const;
    GameModel(Action a, string maptxt);
    ~GameModel();
    Tile** getRawMap() const;
    State getState() const;
};

pair<int, int> operator+(const pair<int, int>& p1, const pair<int, int>& p2);

#endif
