#ifndef _GAME_H_
#define _GAME_H_
#include <string>
#include <vector>
#include "gameModel.h"
#include "cinInputDevice.h"
#include "view.h"
using namespace std;

class Game {
  GameModel* gm;
  InputDevice* id;
  View<Tile> v;
  string maptxt;
  void init();
  void render(string actionString);
  bool createGameModel();
public:
  Game(string maptxt = "");
  virtual ~Game();
  void start();
};

#endif
