#include "arduino.h"
#pragma once

class AnalogSensorController
{
public:
  static const int cAnalogMaxValue = 1023;

public:
  /// Constructor
  AnalogSensorController();

  /// get raw  value[0, cAnalogMaxValue]
  int getRawValue() const;

  /// get normalized value[0, 1]
  float getNormalizedValue() const;
};
