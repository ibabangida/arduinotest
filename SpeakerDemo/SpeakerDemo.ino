#include <SpeakerController.h>
#include <ButtonController.h>
#include <LedController.h>

SpeakerController* p_speaker = nullptr;
ButtonController* p_button = nullptr;
LedController* p_led = nullptr;

void setup()
{
  p_speaker = new SpeakerController(12);
  p_button = new ButtonController(7, 10);
  p_led = new LedController(13);
}

void loop()
{
  p_speaker->sound(SpeakerController::C, 2000);
  delay(3000);
}
