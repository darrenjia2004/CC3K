#include "game.h"

Game::Game(string maptxt) : gm{ unique_ptr<GameModel>(nullptr) }, maptxt{ maptxt } {
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

            GameModel::State state{ gm->getState() };

            render(actionString, state != GameModel::State::LOST);

            if (state == GameModel::State::IN_PROGRESS) {
                continue; //keep going
            }

            if (state == GameModel::State::WON) {
                v.print("Congratulations! You beat the game!");
                v.print("Your score was " + to_string(gm->getPlayer()->calculateScore()));
            }
            else {
                v.print("You lost...");
            }

            v.print("If you would like to play again, enter your race.");
            if (!createGameModel()) {
                break;
            }
        }
    }

    v.print("Quitting game.");
}

bool Game::createGameModel() {
    v.print("Choose your race: (d)warf, (e)lf, (h)uman, or (o)rc.");
    v.print("Alternatively, press q to quit.");
    Command c = id->getUserInput();
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

    gm = make_unique<GameModel>(c.action, maptxt);
    render("");
    return true;
}

void Game::render(string actionString, bool includePlayerInfo) const {
    v.draw(gm->getRawMap(), gm->map.size(), gm->map[0].size(), gm->getPlayer(), gm->getFloor(), actionString, includePlayerInfo);
}
