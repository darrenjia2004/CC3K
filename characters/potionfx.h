#ifndef _POTIONFX_H_
#define _POTIONFX_H_

#include <memory>

class Potionfx{
   public:
    const int atk;
    const int def;
    std::unique_ptr<Potionfx> next;
    int getAtkChange();
    int getDefChange();
    Potionfx(int atk, int def);
    ~Potionfx();
};
#endif
