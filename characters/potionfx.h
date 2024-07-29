#ifndef _POTIONFX_H_
#define _POTIONFX_H_

#include <memory>

class Potionfx{
    std::unique_ptr<Potionfx> next;

   public:
    const int atk;
    const int def;
    Potionfx(int atk, int def);
    int getAtkChange() const;
    int getDefChange() const;
    void setNext(Potionfx* p);
};
#endif
