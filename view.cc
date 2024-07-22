#include "view.h"

template <typename T>
typename enable_if<is_base_of<Drawable, T>::value, void>::type
View::draw(vector<vector<T>>& map) {
    for (auto v : map){
        for (auto t : v){
            cout << t.getChar();
        }
        cout << endl;
    }
}