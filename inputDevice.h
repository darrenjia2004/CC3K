#ifndef _INPUTDEVICE_H_
#define _INPUTDEVICE_H_
#include <string>
#include <vector>
#include "command.h"
using namespace std;

class InputDevice {
 public:
  virtual ~InputDevice(){}
  virtual Command getUserInput() =0;
};

#endif