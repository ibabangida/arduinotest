#include <arduino.h>
#pragma once

class ButtonController
{
public:
  enum EState
  {
    INVALID = -1,
    OFF = 0,
    ON = 1
  };

public:
  /// Constructor
  ButtonController(int pin, int on_detect_count);

  /// update state, keep call for update
  void update();

  /// return EState
  int getState() const;

  /// state changed or not
  bool isChangeState() const;

private:
  int mPin;
  int mOnDetectCount;
  int mState;
  int mDetectCount;
  bool mIsChangeState;
};
