#include "arduino.h"
#pragma once

class LedController
{
public:
  /// Constructor
  LedController(int pin);
  
  /// LED ON
  void on();

  /// LED ON (brightness)
  void on(int brightness);

  /// LED OFF
  void off();

private:
  int mPin;
};
