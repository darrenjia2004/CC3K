#ifndef _POTIONFX_H_
#define _POTIONFX_H_

class Potionfx{
    const int atk;
    const int def;
    Potionfx* nextPotionfx;
   public:
    int getAtkChange();
    int getDefChange();
    Potionfx(int atk, int def);
};
#endif