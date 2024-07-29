#include "gameModel.h"
#include "game.h"

int main(int argc, char *argv[]){
    if (argc>=2){
        Game g{argv[1]};
        g.start();
    }
    else{
        Game g;
        g.start();
    }   
}
