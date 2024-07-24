#ifndef _GAMEMODEL_H_
#define _GAMEMODEL_H_
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

#include "tile.h"

class Player;
class Potion;
class Gold;
class Enemy;

using namespace std;

class GameModel {
    static const int numPotions{ 10 };
    static const int numGolds{ 10 };
    static const int numEnemies{ 20 };

    void init();
    void loadTiles();
    void loadNeighbours();
    void loadChambers();
    void floodFill(Tile& t, int n);
    void generate();
    pair<int, int> addToRandomTile(Entity* e, bool canBeWithPlayer);
    void addGolds(int n);

    pair<int, int> getCoords(Direction d);  // first is row, second is column
    bool inBounds(const pair<int, int>& pos);
    static vector<Direction> getGameDirections();
    pair<int, int> getRandomTile();
    Potion* getRandomPotion();
    Gold* getRandomGold();
    Enemy* getRandomEnemy(bool hasCompass);
    Tile* getRandomNeighbour(const Tile& current);
    void setPotionVis();
    Tile& getPlayerTile();

    pair<int, int> playerCoords;
    int chamberCount;
    const unsigned randomSeed;
    int floor;
    Tile** rawMap;
public:
    static unordered_map<char, bool> potionVisibility;
    vector<vector<Tile>> map;

    string playerTurn(Command c);
    int getFloor();
    Player* getPlayer();
    GameModel();
    ~GameModel();
    Tile** getRawMap();
};

pair<int, int> operator+(const pair<int, int>& p1, const pair<int, int>& p2);

#endif
