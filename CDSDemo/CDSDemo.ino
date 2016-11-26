#include <LedController.h>
#include <AnalogSensorController.h>

LedController* p_led = nullptr;
AnalogSensorController* p_analog = nullptr;
int on_pushed_time;

void setup()
{
  p_analog = new AnalogSensorController();
  p_led = new LedController(13);
  Serial.begin(9600);
}

void loop()
{
  int brightness = 255 * pow(p_analog->getNormalizedValue(), 4);
  Serial.println(brightness);
  p_led->on(brightness);
}
