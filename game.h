#ifndef _GAME_H_
#define _GAME_H_
#include <memory>
#include <string>
#include <vector>
#include "gameModel.h"
#include "cinInputDevice.h"
#include "view.h"
using namespace std;

class Game {
  unique_ptr<GameModel> gm;
  unique_ptr<InputDevice> id;
  View<Tile> v;
  void init();
  void render(string actionString, bool includePlayerInfo = true);
  bool createGameModel();
public:
  Game();
  virtual ~Game();
  void start();
};

#endif
