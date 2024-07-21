#ifndef _TILE_H_
#define _TILE_H_
#include <string>
#include <vector>
using namespace std;

class Tile {
 public:
  int chamberNum;
  char c;
  Tile(char c);
  char getChar();
};

#endif