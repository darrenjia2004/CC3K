#include "view.h"

template <typename T>
typename enable_if<is_base_of<Drawable, T>::value, void>::type
View::draw(vector<vector<T>>& map, Player* p, int floor, string actionString) {
    for (auto v : map){
        for (auto t : v){
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
