#ifndef _GAMEMODEL_H_
#define _GAMEMODEL_H_
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "tile.h"
using namespace std;

class GameModel {
  void init();
  void loadTiles();
 public:
  vector<vector<Tile>> map;
  GameModel();
};

#endif