#include "command.h"


// utility functions
pair<int, int> getCoords(Direction d) {
    switch (d) {
    case Direction::NO:
        return { -1, 0 };
    case Direction::SO:
        return { 1, 0 };
    case Direction::EA:
        return { 0, 1 };
    case Direction::WE:
        return { 0, -1 };
    case Direction::NE:
        return { -1, 1 };
    case Direction::NW:
        return { -1, -1 };
    case Direction::SE:
        return { 1, 1 };
    case Direction::SW:
        return { 1, -1 };
    default:
        return { 0, 0 };
    }
}

vector<Direction> getGameDirections() {
    return {
        Direction::NO,
        Direction::SO,
        Direction::EA,
        Direction::WE,
        Direction::NE,
        Direction::NW,
        Direction::SE,
        Direction::SW,
    };
}