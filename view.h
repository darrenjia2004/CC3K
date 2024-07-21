#ifndef _VIEW_H_
#define _VIEW_H_
#include <string>
#include <vector>
#include <iostream>
#include "tile.h"
using namespace std;

class View {
 public:
    void draw(vector<vector<Tile>> map);
};

#endif