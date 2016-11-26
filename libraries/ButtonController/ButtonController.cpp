#include "ButtonController.h"

ButtonController::ButtonController(int pin, int on_detect_count)
  : mPin(pin)
  , mOnDetectCount(on_detect_count)
  , mState(LOW)
  , mDetectCount(0)
  , mIsChangeState(false)
 {
  pinMode(mPin, INPUT);
 }

void ButtonController::update()
{
  int state = digitalRead(mPin);
  if (state != mState)
  {
    mDetectCount = millis();
    mIsChangeState = true;
  }
  else
  {
    mIsChangeState = false;
  }
  mState = state;
}

int ButtonController::getState() const
{
  if (millis() - mDetectCount < mOnDetectCount) return EState::INVALID;
  return mState == HIGH ? EState::ON : EState::OFF;
}

bool ButtonController::isChangeState() const
{
  return mIsChangeState;
}
