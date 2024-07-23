#ifndef _GAME_H_
#define _GAME_H_
#include <string>
#include <vector>
#include "gameModel.h"
#include "cinInputDevice.h"
#include "view.h"
using namespace std;

class Game {
  GameModel gm;
  InputDevice* id;
  View<Tile> v;
  void init();
  void render(string actionString);
public:
  Game();
  virtual ~Game();
  void start();
};

#endif
