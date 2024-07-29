#ifndef _CININPUTDEVICE_H_
#define _CININPUTDEVICE_H_
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "inputDevice.h"
using namespace std;

class CinInputDevice: public InputDevice {
  static Direction stringToDirection(string s);
 public:
  virtual Command getUserInput() override;
};

#endif
