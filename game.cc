#include "game.h"

Game::Game() : gm{ new GameModel() } {
    init();
}

void Game::init() {
    id = new CinInputDevice();
}

Game::~Game() {
    delete id;
    delete gm;
}

void Game::start() {
    // display game initially
    render("");

    while (true) {
        Command c = id->getUserInput();
        if (c.action == Action::QUIT) {
            cout << "quitting game" << endl;
            break;
        }
        else if (c.action == Action::RESTART) {
            cout << "restarting game" << endl;
            delete gm;
            gm = new GameModel();
            render("");
        }
        else {
            string actionString = gm->playerTurn(c);
            render(actionString);
        }
    }
}

void Game::render(string actionString) {
    v.draw(gm->getRawMap(), gm->map.size(), gm->map[0].size(), gm->getPlayer(), gm->getFloor(), actionString);
}
