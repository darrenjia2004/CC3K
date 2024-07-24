#include "game.h"

Game::Game() {
    rawMap = new Tile * [gm.map.size()];

    for (int i = 0; i < gm.map.size(); ++i) {
        rawMap[i] = &gm.map[i][0];
    }

    init();
}

void Game::init() {
    id = new CinInputDevice();
}

Game::~Game() {
    delete id;
    delete[] rawMap;
}

void Game::start() {
    while (true) {
        Command c = id->getUserInput();
        if (c.action == Action::QUIT) {
            cout << "quitting game" << endl;
            break;
        }
        else {
            string actionString = gm.playerTurn(c);
            render(actionString);
        }
    }
}

void Game::render(string actionString) {
    v.draw(rawMap, gm.map.size(), gm.map[0].size(), gm.getPlayer(), gm.getFloor(), actionString);
}
