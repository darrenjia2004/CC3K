#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>

class Entity;

class Observer {
    public:
        virtual std::string notify(Entity& e) = 0;
        virtual ~Observer(){};
};
#endif
