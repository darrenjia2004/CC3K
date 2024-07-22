#ifndef _GAMEMODEL_H_
#define _GAMEMODEL_H_
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "tile.h"
using namespace std;

class GameModel {
    void init();
    void loadTiles();
    void loadNeighbours();
    void loadChambers();
    void floodFill(Tile& t, int n);
    pair<int, int> getCoords(Direction d);  // first is row, second is column
    bool inBounds(const pair<int, int>& pos);
    static vector<Direction> getGameDirections();
    Tile& getRandomTile();

    int chamberCount;
    const int randomSeed;

   public:
    vector<vector<Tile>> map;
    GameModel();
};

pair<int, int> operator+(const pair<int, int>& p1, const pair<int, int>& p2);

#endif