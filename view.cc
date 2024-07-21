#include "view.h"

void View::draw(vector<vector<Tile>> map){
    for (auto v : map){
        for (auto t : v){
            cout << t.getChar();
        }
        cout << endl;
    }
}