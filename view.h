#ifndef _VIEW_H_
#define _VIEW_H_
#include <string>
#include <vector>
#include <iostream>
#include "drawable.h"
#include "characters/player.h"
using namespace std;

template<typename T> class View {
public:
    enable_if_t<is_base_of<Drawable, T>::value, void>

        draw(T** map, int rows, int cols, Player* p, int floor, string actionString) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << map[i][j].getChar();
            }

            cout << endl;
        }
        // cout << "Race: " << p->getRace() << "Gold: " << p->getGold() << "         Floor: " << floor << endl;
        // cout << "HP: " << p->getHp() << endl;
        // cout << "Atk: " << p->getAtk() << endl;
        // cout << "Def: " << p->getDef() << endl;
        // cout << "Action: " << actionString;
    }
};

#endif
