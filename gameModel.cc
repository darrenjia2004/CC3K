#include "gameModel.h"

GameModel::GameModel() : numChambers{0} {
    init();
}

void GameModel::init() {
    loadTiles();
    loadNeighbours();
    loadChambers();
    // need to do a second pass to assign neighbours and chamber number
}

// method which loads the default map into the tile map
void GameModel::loadTiles() {
    string line;
    ifstream file("defaultMap.txt");
    int row = -1;
    while (getline(file, line)) {
        map.push_back(vector<Tile>());
        row++;
        for (int i = 0; i < line.length(); i++) {
            Tile t{line[i]};
            map[row].push_back(t);
        }
    }
    file.close();
}

void GameModel::loadNeighbours() {
    vector<Direction> dirs{getGameDirections()};

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            for (Direction d : dirs) {
                // for every direction, check if in bounds and add to array
                pair<int, int> neighbourPosition{pair<int, int>(i, j) + getCoords(d)};

                if (inBounds(neighbourPosition)) {
                    map[i][j].setNeighbour(d, &map[neighbourPosition.first][neighbourPosition.second]);
                }
            }
        }
    }
}

void GameModel::loadChambers() {
    for (vector<Tile>& row : map) {
        for (Tile& t : row) {
            // if we find a tile that needs to be filled but hasn't, then fill it with new chamber number
            if (t.c == '.' && t.getChamberNum() == -1) {
                floodFill(t, numChambers);
                ++numChambers;
            }
        }
    }
}

void GameModel::floodFill(Tile& t, int n) {
    auto& neighbours{t.getNeighbours()};
    t.setChamberNum(n);

    for (auto iter = neighbours.begin(); iter != neighbours.end(); ++iter) {
        Tile* neighbour{iter->second};

        // if neighbour needs chamber and doesnt have one assigned, then recurse
        if (neighbour->c == '.' && neighbour->getChamberNum() == -1) {
            floodFill(*neighbour, n);
        }
    }
}

// utility functions
pair<int, int> GameModel::getCoords(Direction d) {
    switch (d) {
        case Direction::NO:
            return {-1, 0};
        case Direction::SO:
            return {1, 0};
        case Direction::EA:
            return {0, 1};
        case Direction::WE:
            return {0, -1};
        case Direction::NE:
            return {-1, 1};
        case Direction::NW:
            return {-1, -1};
        case Direction::SE:
            return {1, 1};
        case Direction::SW:
            return {1, -1};
        default:
            return {0, 0};
    }
}

bool GameModel::inBounds(const pair<int, int>& pos) {
    return pos.first < map.size() && pos.second < map[pos.first].size();
}

pair<int, int> operator+(const pair<int, int>& p1, const pair<int, int>& p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}

vector<Direction> GameModel::getGameDirections() {
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
