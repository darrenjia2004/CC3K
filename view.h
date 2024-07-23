#ifndef _VIEW_H_
#define _VIEW_H_
#include <string>
#include <vector>
#include <iostream>
#include "drawable.h"
#include "characters/player.h"
using namespace std;

class View {
 public:
    template <typename T>
    typename enable_if<is_base_of<Drawable, T>::value, void>::type
    draw(vector<vector<T>>& map, Player* p, int floor, string actionString);
};

#endif
