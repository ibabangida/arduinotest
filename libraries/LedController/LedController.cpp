#include "LedController.h"

LedController::LedController(int pin)
  : mPin(pin)
{
  pinMode(mPin, OUTPUT);  
}

void LedController::on()
{
  digitalWrite(mPin, HIGH);
}

void LedController::on(int brightness)
{
  if (brightness < 0) brightness = 0;
  if (brightness > 255) brightness = 255;
  analogWrite(mPin, brightness);
}

void LedController::off()
{
  digitalWrite(mPin, LOW);
}
