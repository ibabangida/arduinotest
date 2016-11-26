#include "SpeakerController.h"

SpeakerController::SpeakerController(int pin)
  : mPin(pin)
  , mReservedTime(0)
{}

void SpeakerController::sound(ESound type, int time)
{
  if (mReservedTime > millis()) return;
  tone(mPin, type, time);
  mReservedTime = millis() + time;
}
