#include "AnalogSensorController.h"

AnalogSensorController::AnalogSensorController()
{
  // automatically recognized as input
}

int AnalogSensorController::getRawValue() const
{
  return analogRead(0);
}

float AnalogSensorController::getNormalizedValue() const
{
  return static_cast<float>(analogRead(0)) / static_cast<float>(cAnalogMaxValue);
}
