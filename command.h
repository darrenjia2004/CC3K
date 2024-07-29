#ifndef _COMMAND_H_
#define _COMMAND_H_
#include <vector>
#include <utility>
#include <string>
using namespace std;

enum class Action {
    MOVE,
    USE,
    ATTACK,
    SELECTHUMAN,
    SELECTELF,
    SELECTDWARF,
    SELECTORC,
    RESTART,
    QUIT,
    NONE
};

enum class Direction {
    NO,
    SO,
    EA,
    WE,
    NE,
    NW,
    SE,
    SW,
    NONE
};

pair<int, int> getCoords(Direction d);
vector<Direction> getGameDirections();
string getDirectionName(Direction d);

class Command {
  public:
    Action action;
    Direction direction;
    Command(Action a, Direction d = Direction::NONE): action{a},direction{d}{}
};

#endif
