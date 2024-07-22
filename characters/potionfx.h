#ifndef _POTIONFX_H_
#define _POTIONFX_H_

class Potionfx{
    const int atk;
    const int def;
   public:
    Potionfx* next;
    int getAtkChange();
    int getDefChange();
    Potionfx(int atk, int def);
};
#endif