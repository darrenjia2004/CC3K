#include "game.h"

Game::Game() : gm{ nullptr } {
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

            GameModel::State state{gm->getState()};

            if(state == GameModel::State::IN_PROGRESS){
                render(actionString);
            }
            else{
                if(state == GameModel::State::WON){
                    v.print("Congratulations! You beat the game!");
                    v.print("Your score was " + to_string(gm->getPlayer()->calculateScore()));
                }
                else{
                    v.print("You died :(");
                }

                v.print("If you would like to play again, enter your race.");
                if (!createGameModel()) {
                    break;
                }
            }
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

    delete gm;
    gm = new GameModel(c.action);
    render("");
    return true;
}

void Game::render(string actionString) {
    v.draw(gm->getRawMap(), gm->map.size(), gm->map[0].size(), gm->getPlayer(), gm->getFloor(), actionString);
}
