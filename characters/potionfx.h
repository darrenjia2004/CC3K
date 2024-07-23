#ifndef _POTIONFX_H_
#define _POTIONFX_H_

class Potionfx{
   public:
    const int atk;
    const int def;
    Potionfx* next;
    int getAtkChange();
    int getDefChange();
    Potionfx(int atk, int def);
    ~Potionfx();
};
#endif
