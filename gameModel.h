#ifndef _GAMEMODEL_H_
#define _GAMEMODEL_H_
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
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
    int floor;
    pair<int, int> stairCoords;
    Tile** rawMap;

    void init();
    void loadTiles();
    void loadNeighbours();
    void loadChambers();
    void floodFill(Tile& t, int n);
    void generate();
    pair<int, int> addToRandomTile(Entity* e, bool canBeWithPlayer);

    bool inBounds(const pair<int, int>& pos);
    pair<int, int> getRandomTile();
    Potion* getRandomPotion();
    Gold* getRandomGold();
    Enemy* getRandomEnemy(bool hasCompass);
    Tile* getRandomNeighbour(const Tile& current);
    void setPotionVis();
    Tile& getPlayerTile();
    void generatePlayer(Player* player = nullptr);
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
    int getFloor();
    Player* getPlayer();
    GameModel(Action a);
    ~GameModel();
    Tile** getRawMap();
    State getState();
};

pair<int, int> operator+(const pair<int, int>& p1, const pair<int, int>& p2);

#endif
