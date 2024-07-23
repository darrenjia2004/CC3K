#ifndef _VIEW_H_
#define _VIEW_H_
#include <string>
#include <vector>
#include <iostream>
#include "drawable.h"
#include "characters/player.h"
using namespace std;
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

template<typename T> class View {
    string getColor(char c){
        switch (c) {
            case '@':
                return BOLDCYAN;
            case '\\':
                return BOLDMAGENTA;
            case 'C':
            case 'B':
            case 'P':
                return BLUE;
            case '0':
            case '1':
            case '2':
                return GREEN;
            case '3':
            case '4':
            case '5':
                return RED;
            case '6':
            case '7':
            case '8':
            case '9':
                return BOLDYELLOW;
            case 'V':
            case 'W':
            case 'N':
            case 'M':
            case 'D':
            case 'X':
            case 'T':
                return BOLDRED;
            default:
                return "";
        }
    }
public:
    enable_if_t<is_base_of<Drawable, T>::value, void>

        draw(T** map, int rows, int cols, Player* p, int floor, string actionString) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                char c = map[i][j].getChar();
                cout << getColor(c) << c << RESET;
            }

            cout << RESET << endl;
        }
        // cout << "Race: " << p->getRace() << "Gold: " << p->getGold() << "         Floor: " << floor << endl;
        // cout << "HP: " << p->getHp() << endl;
        // cout << "Atk: " << p->getAtk() << endl;
        // cout << "Def: " << p->getDef() << endl;
        // cout << "Action: " << actionString;
    }
};

#endif
