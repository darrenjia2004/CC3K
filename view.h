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
    void draw(vector<vector<T>>& map, Player* p, int floor, string actionString) {
        for (auto v : map) {
            for (auto t : v) {
                cout << t.getChar();
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