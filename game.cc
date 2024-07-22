#include "game.h"

Game::Game(){
    init();
}

void Game::init(){
    id = new CinInputDevice();
}

Game::~Game(){
    delete id;
}

void Game::start(){
    while (true){
        Command c = id->getUserInput();
        if(c.action == Action::QUIT){
            cout << "quitting game" << endl;
            break;
        }
        else{
            render();
            cout << "command received, calling player turn" << endl;
        }
    }
}

void Game::render(){
    v.draw(gm.map);
}