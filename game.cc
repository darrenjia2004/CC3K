#include "game.h"

Game::Game() : gm{ unique_ptr<GameModel>(nullptr) } {
    init();
}

void Game::init() {
    id = make_unique<CinInputDevice>(CinInputDevice());
}

Game::~Game() {
}

void Game::start() {
    bool initialQuit{ createGameModel() };

    while (initialQuit) {
        Command c = id->getUserInput();
        if (c.action == Action::QUIT) {
            break;
        }
        else if (c.action == Action::RESTART) {
            if (!createGameModel()) {
                break;
            }
        }
        else {
            string actionString = gm->playerTurn(c);
            render(actionString);
        }
    }

    v.print("Quitting game.");
}

bool Game::createGameModel() {
    v.print("Choose your race: (d)warf, (e)lf, (h)uman, or (o)rc.");
    v.print("Alternatively, press q to quit.");
    Command c{ id->getUserInput() };
    while ((c.action != Action::SELECTDWARF)
        && (c.action != Action::SELECTELF)
        && (c.action != Action::SELECTHUMAN)
        && (c.action != Action::SELECTORC)
        && (c.action != Action::QUIT)
        ) {
        c = id->getUserInput();
    }

    if (c.action == Action::QUIT) {
        return false;
    }

    gm = unique_ptr<GameModel>(new GameModel(c.action));
    render("");
    return true;
}

void Game::render(string actionString) {
    v.draw(gm->getRawMap(), gm->map.size(), gm->map[0].size(), gm->getPlayer(), gm->getFloor(), actionString);
}
