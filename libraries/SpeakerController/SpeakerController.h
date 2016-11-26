#include "arduino.h"
#pragma once

class SpeakerController
{
public:
  enum ESound
  {
    C = 262,  ///< ド 
    D = 294,  ///< レ
    E = 330,  ///< ミ
    F = 349,  ///< ファ
    G = 392,  ///< ソ
    A = 440,  ///< ラ
    B = 494   ///< シ
  };

public:
  /// Constructor
  SpeakerController(int pin);

  /// Sound
  void sound(ESound type, int time);

private:
  int mPin;
  int mReservedTime;
};
