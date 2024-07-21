#include "gameModel.h"

GameModel::GameModel(){
    init();
}

void GameModel::init(){
    loadTiles();
    //need to do a second pass to assign neighbours and chamber number
}

// method which loads the default map into the tile map
void GameModel::loadTiles(){
    string line;
    ifstream file("defaultMap.txt");
    int row = -1;
    while (getline(file, line)){
        map.push_back(vector<Tile>());
        row++;
        for (int i =0; i<line.length(); i++){
            Tile t{line[i]};
            map[row].push_back(t);
        }
    }
    file.close();
}