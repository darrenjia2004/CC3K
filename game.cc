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
            string actionString = gm.playerTurn(c);
            actionString = "this is the string for the action the player has performed";
            render(actionString);
        }
    }
}

void Game::render(string actionString){
    v.draw(gm.map, gm.getPlayer(), gm.getFloor(), actionString);
}