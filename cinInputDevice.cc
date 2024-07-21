#include "cinInputDevice.h"

Command CinInputDevice::getUserInput(){
    string line;
    string op;
    while(getline(cin, line)){
        stringstream conv(line);
        if (!(conv >> op)) continue;

        if (op == "h"){
            return Command{Action::SELECTHUMAN};
        }
        else if(op == "d"){
            return Command{Action::SELECTDWARF};
        }
        else if(op == "e"){
            return Command{Action::SELECTELF};
        }
        else if(op == "o"){
            return Command{Action::SELECTORC};
        }
        else if(op == "r"){
            return Command{Action::RESTART};
        }
        else if(op == "q"){
            return Command{Action::QUIT};
        }
        else if(op == "u"){
            Action a = Action::USE;
            if (!(conv >> op)) continue;
            Direction d = stringToDirection(op);
            if (d == Direction::NONE){
                continue;
            }
            return Command{a, d};
        }
        else if(op == "a"){
            Action a = Action::ATTACK;
            if (!(conv >> op)) continue;
            Direction d = stringToDirection(op);
            if (d == Direction::NONE){
                continue;
            }
            return Command{a, d};
        }
        else{
            Direction d = stringToDirection(op);
            if (d == Direction::NONE){
                continue;
            }
            return Command{Action::MOVE, d};
        }
    }
    
}

Direction CinInputDevice::stringToDirection(string s){
    if (s == "no"){
        return Direction::NO;
    }
    else if (s == "so"){
        return Direction::SO;
    }
    else if (s == "ea"){
        return Direction::EA;
    }
    else if (s == "we"){
        return Direction::WE;
    }
    else if (s == "nw"){
        return Direction::NW;
    }
    else if (s == "ne"){
        return Direction::NE;
    }
    else if (s == "sw"){
        return Direction::SW;
    }
    else if (s == "se"){
        return Direction::SE;
    }
    else {
        return Direction::NONE;
    }
}