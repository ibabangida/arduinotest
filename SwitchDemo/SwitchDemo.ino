#include <LedController.h>
#include <ButtonController.h>

LedController* p_led = nullptr;
ButtonController* p_button = nullptr;
int on_pushed_time;

void setup()
{
  p_button = new ButtonController(7, 10);
  p_led = new LedController(13);
  Serial.begin(9600);
}

void loop()
{
  p_button->update();
  if (p_button->isChangeState()) on_pushed_time = millis();

  switch(p_button->getState())
  {
    case ButtonController::EState::ON:
    {
      int current_time = millis();
      if (current_time > on_pushed_time)
      {
        int brightness = (current_time - on_pushed_time) / 10;
        if (brightness > 255) brightness = 255;
        Serial.println(brightness);
        p_led->on(brightness);
      }
    }
    break;
    case ButtonController::EState::OFF:
    case ButtonController::EState::INVALID:
    default:
    {
      p_led->off();  
    }
    break;
  }
}
