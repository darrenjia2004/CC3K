#ifndef _COMMAND_H_
#define _COMMAND_H_
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

class Command {
  public:
    Action action;
    Direction direction;
    Command(Action a, Direction d = Direction::NONE): action{a},direction{d}{}
};

#endif